/* $Id$ */

/*
 * Copyright 2002-2011, The TenDRA Project.
 *
 * See doc/copyright/ for the full copyright terms.
 */


#include "lctlexer.h"


#include "lctlexer.h"
#include "lctsyntax.h"
#include <shared/error.h>

int crt_lct_token ;
int saved_lct_token ;

char lct_token_buff [2000];
static char *lct_token_end = lct_token_buff + sizeof(lct_token_buff);
static char* lct_token_current;

NStringT lct_token_nstring;

struct lexi_lct_state lct_lexer_state;

static int 
lexi_lct_getchar(struct lexi_lct_state* state) 
{
	int c =fgetc(state->input);
	if(c == '\n') 
		crt_line_no++;
	if(c == EOF) 
		return LEXI_EOF;
	return c;
}

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

int lexi_lct_readchar(struct lexi_lct_state *state) {
	if (state->buffer_index) {
		return lexi_lct_pop(state);
	}

	return lexi_lct_getchar(state);
}
void lexi_lct_push(struct lexi_lct_state *state, const int c) {
	assert(state);
	assert(state->buffer_index < sizeof state->buffer / sizeof *state->buffer);
	state->buffer[state->buffer_index++] = c;
}

int lexi_lct_pop(struct lexi_lct_state *state) {
	assert(state);
	assert(state->buffer_index > 0);
	return state->buffer[--state->buffer_index];
}

void lexi_lct_flush(struct lexi_lct_state *state) {
	state->buffer_index = 0;
}


/* LOOKUP TABLE */

typedef uint8_t lookup_type;
static lookup_type lookup_tab[] = {
	   0,    0,    0,    0,    0,    0,    0,    0,    0,  0x1,  0x1,    0, 
	   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0, 
	   0,    0,    0,    0,    0,    0,    0,    0,  0x1,    0,    0,    0, 
	   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0, 
	 0x2,  0x2,  0x2,  0x2,  0x2,  0x2,  0x2,  0x2,  0x2,  0x2,    0,    0, 
	   0,    0,    0,    0,    0,  0x6,  0x6,  0x6,  0x6,  0x6,  0x6,  0x6, 
	 0x6,  0x6,  0x6,  0x6,  0x6,  0x6,  0x6,  0x6,  0x6,  0x6,  0x6,  0x6, 
	 0x6,  0x6,  0x6,  0x6,  0x6,  0x6,  0x6,    0,    0,    0,    0,  0x6, 
	   0,  0x6,  0x6,  0x6,  0x6,  0x6,  0x6,  0x6,  0x6,  0x6,  0x6,  0x6, 
	 0x6,  0x6,  0x6,  0x6,  0x6,  0x6,  0x6,  0x6,  0x6,  0x6,  0x6,  0x6, 
	 0x6,  0x6,  0x6,    0,    0,    0,    0,    0,    0,    0,    0,    0, 
	   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0, 
	   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0, 
	   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0, 
	   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0, 
	   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0, 
	   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0, 
	   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0, 
	   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0, 
	   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0, 
	   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0, 
	   0,    0,    0,    0
};

bool lexi_lct_group(enum lexi_lct_groups group, int c) {
	if (c == LEXI_EOF) {
		return 0;
	}
	return lookup_tab[c] & group;
}


#include <string.h>
int lexi_lct_keyword(const char *identifier, int notfound) {
	if (0 == strcmp(identifier, "ACTION")) return lct_lex_action_Hkw;
	if (0 == strcmp(identifier, "ARGUMENT")) return lct_lex_argument_Hkw;
	if (0 == strcmp(identifier, "HEADERS")) return lct_lex_header_Hkw;
	if (0 == strcmp(identifier, "MAP")) return lct_lex_map_Hkw;
	if (0 == strcmp(identifier, "TRAILERS")) return lct_lex_trailer_Hkw;
	return notfound;
}
/* PRE-PASS ANALYSERS */

void lexi_lct_init(struct lexi_lct_state *state, FILE_P_lct input) {
	state->zone = lexi_lct_read_token;
	state->buffer_index = 0;
	state->input = input;
}
/* ZONES PASS ANALYSER PROTOTYPES*/

static int lexi_lct_read_token_codereferencezone(struct lexi_lct_state *state);
static int lexi_lct_read_token_codeidentifierzone(struct lexi_lct_state *state);
static int lexi_lct_read_token_code_area(struct lexi_lct_state *state);
static void lexi_lct_read_token_LineComment(struct lexi_lct_state *state);
static void lexi_lct_read_token_Comment(struct lexi_lct_state *state);
static int lexi_lct_read_token_identifierzone(struct lexi_lct_state *state);
/* MAIN PASS ANALYSERS */


/* MAIN PASS ANALYSER for codereferencezone */
static int
lexi_lct_read_token_codereferencezone(struct lexi_lct_state *state)
{
	start: {
		int c0 = lexi_lct_readchar(state);
		if (!lexi_lct_group(lexi_lct_group_alphanum, c0)) {
			lexi_lct_push(state, c0);
			/* ACTION <finalize_token_buffer> */
			{

       	if(lct_token_current==lct_token_end) {
		error(ERROR_FATAL, "Buffer overflow: trailing 0");
	       *(lct_token_end-1) = 0;		
	} else {
	       *lct_token_current++ = 0;	
	}
			}
			/* END ACTION <finalize_token_buffer> */
			return lct_lex_code_Hreference;
		}

		/* DEFAULT */
		/* ACTION <push_token_buffer> */
		{

       	if(lct_token_current==lct_token_end-1)
		error(ERROR_FATAL, "Buffer overflow");
	else 
	       *lct_token_current++ = c0;
		}
		/* END ACTION <push_token_buffer> */
		goto start; /* DEFAULT */
	}
}

/* MAIN PASS ANALYSER for codeidentifierzone */
static int
lexi_lct_read_token_codeidentifierzone(struct lexi_lct_state *state)
{
	start: {
		int c0 = lexi_lct_readchar(state);
		if (!lexi_lct_group(lexi_lct_group_alphanum, c0)) {
			lexi_lct_push(state, c0);
			/* ACTION <finalize_token_buffer> */
			{

       	if(lct_token_current==lct_token_end) {
		error(ERROR_FATAL, "Buffer overflow: trailing 0");
	       *(lct_token_end-1) = 0;		
	} else {
	       *lct_token_current++ = 0;	
	}
			}
			/* END ACTION <finalize_token_buffer> */
			return lct_lex_code_Hidentifier;
		}

		/* DEFAULT */
		/* ACTION <push_token_buffer> */
		{

       	if(lct_token_current==lct_token_end-1)
		error(ERROR_FATAL, "Buffer overflow");
	else 
	       *lct_token_current++ = c0;
		}
		/* END ACTION <push_token_buffer> */
		goto start; /* DEFAULT */
	}
}

/* MAIN PASS ANALYSER for code_area */
static int
lexi_lct_read_token_code_area(struct lexi_lct_state *state)
{
	start: {
		int c0 = lexi_lct_readchar(state);
		switch (c0) {
		case LEXI_EOF: {
				return lct_lex_code_Heof;
			}

		case '@': {
				int c1 = lexi_lct_readchar(state);
				switch (c1) {
				case '@': {
						return lct_lex_code_Hat;
					}

				case '&': {
						int c2 = lexi_lct_readchar(state);
						if (lexi_lct_group(lexi_lct_group_alpha, c2)) {
							/* ACTION <init_token_buffer> */
							{

	lct_token_current=lct_token_buff;
							}
							/* END ACTION <init_token_buffer> */
							/* ACTION <push_token_buffer> */
							{

       	if(lct_token_current==lct_token_end-1)
		error(ERROR_FATAL, "Buffer overflow");
	else 
	       *lct_token_current++ = c2;
							}
							/* END ACTION <push_token_buffer> */
							return lexi_lct_read_token_codereferencezone(state);
						}
						lexi_lct_push(state, c2);
					}
					break;

				case '}': {
						state->zone = lexi_lct_read_token;
						return lct_lex_code_Hend;
					}

				}
				if (lexi_lct_group(lexi_lct_group_alpha, c1)) {
					/* ACTION <init_token_buffer> */
					{

	lct_token_current=lct_token_buff;
					}
					/* END ACTION <init_token_buffer> */
					/* ACTION <push_token_buffer> */
					{

       	if(lct_token_current==lct_token_end-1)
		error(ERROR_FATAL, "Buffer overflow");
	else 
	       *lct_token_current++ = c1;
					}
					/* END ACTION <push_token_buffer> */
					return lexi_lct_read_token_codeidentifierzone(state);
				}
				lexi_lct_push(state, c1);
				return lct_lex_lone_Hcode_Hat;
			}

		}

		/* DEFAULT */
		/* ACTION <get_code_lct_string> */
		{
			int ZT1;

	int c = c0;
	DStringT dstring;
	dstring_init(&dstring);
	do {
		dstring_append_char(&dstring, c) ;
		c = lexi_lct_readchar(&lct_lexer_state);
        } while(c!='@' && c!=LEXI_EOF) ;

	lexi_lct_push(&lct_lexer_state, c);
	
	dstring_to_nstring(&dstring,&lct_token_nstring);
	dstring_destroy(&dstring);
	ZT1 = lct_lex_code_Hstring;
			return ZT1;
		}
		/* END ACTION <get_code_lct_string> */
		goto start; /* DEFAULT */
	}
}

/* MAIN PASS ANALYSER for LineComment */
static void
lexi_lct_read_token_LineComment(struct lexi_lct_state *state)
{
	start: {
		int c0 = lexi_lct_readchar(state);
		if (c0 == '\n') {
			return;
		}

		/* DEFAULT */
		goto start; /* DEFAULT */
	}
}

/* MAIN PASS ANALYSER for Comment */
static void
lexi_lct_read_token_Comment(struct lexi_lct_state *state)
{
	start: {
		int c0 = lexi_lct_readchar(state);
		if (c0 == '*') {
			int c1 = lexi_lct_readchar(state);
			if (c1 == '/') {
				return;
			}
			lexi_lct_push(state, c1);
		}

		/* DEFAULT */
		goto start; /* DEFAULT */
	}
}

/* MAIN PASS ANALYSER for identifierzone */
static int
lexi_lct_read_token_identifierzone(struct lexi_lct_state *state)
{
	start: {
		int c0 = lexi_lct_readchar(state);
		if (!lexi_lct_group(lexi_lct_group_alphanum, c0)) {
			lexi_lct_push(state, c0);
			/* ACTION <finalize_token_buffer> */
			{

       	if(lct_token_current==lct_token_end) {
		error(ERROR_FATAL, "Buffer overflow: trailing 0");
	       *(lct_token_end-1) = 0;		
	} else {
	       *lct_token_current++ = 0;	
	}
			}
			/* END ACTION <finalize_token_buffer> */
			/* ACTION <token_keyword_match> */
			{
				int ZT1;

	ZT1 = lexi_lct_keyword(lct_token_buff, lct_lex_identifier);
				return ZT1;
			}
			/* END ACTION <token_keyword_match> */
		}

		/* DEFAULT */
		/* ACTION <push_token_buffer> */
		{

       	if(lct_token_current==lct_token_end-1)
		error(ERROR_FATAL, "Buffer overflow");
	else 
	       *lct_token_current++ = c0;
		}
		/* END ACTION <push_token_buffer> */
		goto start; /* DEFAULT */
	}
}

/* MAIN PASS ANALYSER for the global zone */
int
lexi_lct_read_token(struct lexi_lct_state *state)
{
	if (state->zone != lexi_lct_read_token)
		return state->zone(state);
	start: {
		int c0 = lexi_lct_readchar(state);
		if (lexi_lct_group(lexi_lct_group_white, c0)) goto start;
		switch (c0) {
		case '@': {
				int c1 = lexi_lct_readchar(state);
				if (c1 == '{') {
					state->zone = lexi_lct_read_token_code_area;
					return lct_lex_code_Hstart;
				}
				lexi_lct_push(state, c1);
			}
			break;

		case '/': {
				int c1 = lexi_lct_readchar(state);
				switch (c1) {
				case '/': {
						lexi_lct_read_token_LineComment(state);
						goto start;	/* pure function */
					}

				case '*': {
						lexi_lct_read_token_Comment(state);
						goto start;	/* pure function */
					}

				}
				lexi_lct_push(state, c1);
			}
			break;

		case LEXI_EOF: {
				return lct_lex_eof;
			}

		case '-': {
				int c1 = lexi_lct_readchar(state);
				if (c1 == '>') {
					return lct_lex_arrow;
				}
				lexi_lct_push(state, c1);
			}
			break;

		case ',': {
				return lct_lex_comma;
			}

		case ':': {
				return lct_lex_colon;
			}

		case ';': {
				return lct_lex_semicolon;
			}

		case '&': {
				return lct_lex_reference;
			}

		case '=': {
				return lct_lex_define;
			}

		case ')': {
				return lct_lex_close;
			}

		case '(': {
				return lct_lex_open;
			}

		}
		if (lexi_lct_group(lexi_lct_group_alpha, c0)) {
			/* ACTION <init_token_buffer> */
			{

	lct_token_current=lct_token_buff;
			}
			/* END ACTION <init_token_buffer> */
			/* ACTION <push_token_buffer> */
			{

       	if(lct_token_current==lct_token_end-1)
		error(ERROR_FATAL, "Buffer overflow");
	else 
	       *lct_token_current++ = c0;
			}
			/* END ACTION <push_token_buffer> */
			return lexi_lct_read_token_identifierzone(state);
		}

		/* DEFAULT */
		return lct_lex_unknown;
	}
}



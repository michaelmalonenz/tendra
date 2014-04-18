
/*
 * Automatically generated by lexi version 2.0
 */

#include "lexer.h"



	#include <assert.h>
	#include <stdio.h>

	#include <shared/error.h>

	#include "lexer.h"
	#include "environ.h"

	#define lexi_unknown_token lex_unknown_token

	static int lexi_getchar(struct lexi_state *state) {
		int c;

		assert(state != NULL);
		assert(state->lex_state.file != NULL);

		c = fgetc(state->lex_state.file);
		if (c == EOF) {
			return LEXI_EOF;
		}

		return c;
	}

	static void buf_push(struct lex_state *state, char c) {
		assert(state != NULL);

		if (state->bufp == state->buf + sizeof state->buf - 1) {
			error(ERROR_FATAL, "buffer overflow");
		}

		*state->bufp++ = c;
	}

	static void ref_push(struct lex_state *state, char c) {
		assert(state != NULL);

		if (state->refp == state->buf + sizeof state->buf - 1) {
			error(ERROR_FATAL, "buffer overflow");
		}

		*state->refp++ = c;
	}

#include <assert.h>
int lexi_readchar(struct lexi_state *state) {
	if (state->buffer_index) {
		return lexi_pop(state);
	}

	return lexi_getchar(state);
}
void lexi_push(struct lexi_state *state, const int c) {
	assert(state);
	assert((size_t) state->buffer_index < sizeof state->buffer / sizeof *state->buffer);
	state->buffer[state->buffer_index++] = c;
}

int lexi_pop(struct lexi_state *state) {
	assert(state);
	assert(state->buffer_index > 0);
	return state->buffer[--state->buffer_index];
}

void lexi_flush(struct lexi_state *state) {
	state->buffer_index = 0;
}


/* LOOKUP TABLE */

typedef unsigned char lookup_type;
static lookup_type lookup_tab[] = {
	   0,    0,    0,    0,    0,    0,    0,    0,    0,  0x1,  0x1,    0, 
	   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0, 
	   0,    0,    0,    0,    0,    0,    0,    0,  0x1,    0,    0,    0, 
	   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0, 
	 0x2,  0x2,  0x2,  0x2,  0x2,  0x2,  0x2,  0x2,  0x2,  0x2,    0,    0, 
	   0,    0,    0,    0,    0,  0x2,  0x2,  0x2,  0x2,  0x2,  0x2,  0x2, 
	 0x2,  0x2,  0x2,  0x2,  0x2,  0x2,  0x2,  0x2,  0x2,  0x2,  0x2,  0x2, 
	 0x2,  0x2,  0x2,  0x2,  0x2,  0x2,  0x2,    0,    0,    0,    0,  0x2, 
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
	   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0, 
	   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0, 
	   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0, 
	   0,    0,    0,    0
};

int lexi_group(enum lexi_groups group, int c) {
	if (c == LEXI_EOF) {
		return 0;
	}
	return lookup_tab[c] & group;
}


/* PRE-PASS ANALYSERS */

void lexi_init(struct lexi_state *state, lex_state lex_state) {
	state->zone = lexi_read_token;
	state->buffer_index = 0;
	state->lex_state = lex_state;
}
/* ZONES PASS ANALYSER PROTOTYPES*/

static int lexi_read_token_name(struct lexi_state *state);
static void lexi_read_token_reference(struct lexi_state *state);
static int lexi_read_token_string(struct lexi_state *state);
static void lexi_read_token_comment(struct lexi_state *state);
/* MAIN PASS ANALYSERS */


/* MAIN PASS ANALYSER for name */
static int
lexi_read_token_name(struct lexi_state *state)
{
	start: {
		int c0 = lexi_readchar(state);
		if (lexi_group(lexi_group_ident, c0)) {
			/* ACTION <buf_push> */
			{

	buf_push(&state->lex_state, c0);
			}
			/* END ACTION <buf_push> */
			goto start;	/* leaf */
		} else if (!lexi_group(lexi_group_ident, c0)) {
			lexi_push(state, c0);
			/* ACTION <buf_fini> */
			{

	*state->lex_state.bufp++ = '\0';
			}
			/* END ACTION <buf_fini> */
			return lex_name;
		}

		/* DEFAULT */
		return lexi_unknown_token;
	}
}

/* MAIN PASS ANALYSER for reference */
static void
lexi_read_token_reference(struct lexi_state *state)
{
	start: {
		int c0 = lexi_readchar(state);
		if (c0 == '>') {
			/* ACTION <ref_fini> */
			{

	const char *var;
	const char *p;

	*state->lex_state.refp++ = '\0';

	var = envvar_get(envvars, state->lex_state.ref);
	if (var == NULL) {
		/* TODO: file and line */
		error(ERROR_FATAL, "Undefined variable <%s>", state->lex_state.ref);
	}

	for (p = var; *p != '\0'; p++) {
		buf_push(&state->lex_state, *p);
	}
			}
			/* END ACTION <ref_fini> */
			return;
		}

		/* DEFAULT */
		/* ACTION <ref_push> */
		{

	ref_push(&state->lex_state, c0);
		}
		/* END ACTION <ref_push> */
		goto start; /* DEFAULT */
	}
}

/* MAIN PASS ANALYSER for string */
static int
lexi_read_token_string(struct lexi_state *state)
{
	start: {
		int c0 = lexi_readchar(state);
		switch (c0) {
		case '<': {
				/* ACTION <ref_init> */
				{

	state->lex_state.refp = state->lex_state.ref;
				}
				/* END ACTION <ref_init> */
				lexi_read_token_reference(state);
				goto start;	/* pure function */
			}

		case '\\': {
				int c1 = lexi_readchar(state);
				switch (c1) {
				case 't': {
						/* ACTION <buf_esc> */
						{

	switch (c1) {
	case 'n': buf_push(&state->lex_state, '\n'); break;
	case 't': buf_push(&state->lex_state, '\t'); break;

	default:
		error(ERROR_FATAL, "unrecognised escape");
	}
						}
						/* END ACTION <buf_esc> */
						goto start;	/* leaf */
					}

				case 'n': {
						/* ACTION <buf_esc> */
						{

	switch (c1) {
	case 'n': buf_push(&state->lex_state, '\n'); break;
	case 't': buf_push(&state->lex_state, '\t'); break;

	default:
		error(ERROR_FATAL, "unrecognised escape");
	}
						}
						/* END ACTION <buf_esc> */
						goto start;	/* leaf */
					}

				case '\\': {
						/* ACTION <buf_push> */
						{

	buf_push(&state->lex_state, c0);
						}
						/* END ACTION <buf_push> */
						/* ACTION <buf_push> */
						{

	buf_push(&state->lex_state, c0);
						}
						/* END ACTION <buf_push> */
						goto start;	/* leaf */
					}

				case '"': {
						/* ACTION <buf_push> */
						{

	buf_push(&state->lex_state, c1);
						}
						/* END ACTION <buf_push> */
						goto start;	/* leaf */
					}

				}
				lexi_push(state, c1);
			}
			break;

		case '"': {
				/* ACTION <buf_fini> */
				{

	*state->lex_state.bufp++ = '\0';
				}
				/* END ACTION <buf_fini> */
				return lex_string;
			}

		}

		/* DEFAULT */
		/* ACTION <buf_push> */
		{

	buf_push(&state->lex_state, c0);
		}
		/* END ACTION <buf_push> */
		goto start; /* DEFAULT */
	}
}

/* MAIN PASS ANALYSER for comment */
static void
lexi_read_token_comment(struct lexi_state *state)
{
	start: {
		int c0 = lexi_readchar(state);
		if (c0 == '*') {
			int c1 = lexi_readchar(state);
			if (c1 == '/') {
				return;
			}
			lexi_push(state, c1);
		}

		/* DEFAULT */
		goto start; /* DEFAULT */
	}
}

/* MAIN PASS ANALYSER for the global zone */
int
lexi_read_token(struct lexi_state *state)
{
	if (state->zone != lexi_read_token)
		return state->zone(state);
	start: {
		int c0 = lexi_readchar(state);
		if (lexi_group(lexi_group_white, c0)) goto start;
		switch (c0) {
		case LEXI_EOF: {
				return lex_eof;
			}

		case '+': {
				return lex_replace;
			}

		case '>': {
				return lex_append;
			}

		case '<': {
				return lex_prepend;
			}

		case '"': {
				/* ACTION <buf_init> */
				{

	state->lex_state.bufp = state->lex_state.buf;
				}
				/* END ACTION <buf_init> */
				return lexi_read_token_string(state);
			}

		case '/': {
				int c1 = lexi_readchar(state);
				if (c1 == '*') {
					lexi_read_token_comment(state);
					goto start;	/* pure function */
				}
				lexi_push(state, c1);
			}
			break;

		}
		if (lexi_group(lexi_group_ident, c0)) {
			/* ACTION <buf_init> */
			{

	state->lex_state.bufp = state->lex_state.buf;
			}
			/* END ACTION <buf_init> */
			/* ACTION <buf_push> */
			{

	buf_push(&state->lex_state, c0);
			}
			/* END ACTION <buf_push> */
			return lexi_read_token_name(state);
		}

		/* DEFAULT */
		return lexi_unknown_token;
	}
}


	void lex_init(struct lexi_state *state, FILE *f) {
		assert(state != NULL);
		assert(f != NULL);

		lexi_init(state, state->lex_state);

		state->lex_state.file = f;
	}



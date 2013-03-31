/* $Id$ */

/*
 * Copyright 2002-2012, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */

#ifndef CONFIG_INCLUDED
#define CONFIG_INCLUDED

#ifdef __GNUC__
#ifdef __sun__
/* SunOS 4.1.3 doesn't have these in stdio.h */
extern int fputs(const char *, FILE*);
extern int fputc(int , FILE*);
extern int fprintf(FILE*,const char*, ...);
extern size_t fread(void*, size_t, size_t, FILE*);
extern int fflush(FILE *);
extern int fclose(FILE *);
extern int fgetc(FILE *);
extern int remove(const char *);
extern void setbuf(FILE *, char *);
#endif
#endif


/* Settings for SunOS 4 and Solaris 1 */
#define SYSV_ABI		0
#define DWARF			0


/* CONFIGURATION OPTIONS */

#define GENCOMPAT		1


/* foralls config */
#define remove_unused_counters 0
#define remove_unused_index_counters 1

#define good_index_factor(f)0
#define good_pointer_factor(f)1

#if SYSV_ABI
#define use_long_double		1
#else
#define use_long_double		0
#endif

	/* condition for shape to be treated as a struct */
#define sparccpd(s)(name(s) == cpdhd || name(s) == nofhd || \
			name(s) == shcomplexhd || shape_size(s) >64 || \
			name(s) == u64hd || name(s) == s64hd)

#endif /* CONFIG_INCLUDED */


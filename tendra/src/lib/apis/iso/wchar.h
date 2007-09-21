#		 Crown Copyright (c) 1997
#
#   This TenDRA(r) Computer Program is subject to Copyright
#   owned by the United Kingdom Secretary of State for Defence
#   acting through the Defence Evaluation and Research Agency
#   (DERA).  It is made available to Recipients with a
#   royalty-free licence for its use, reproduction, transfer
#   to other parties and amendment for any purpose not excluding
#   product development provided that any such use et cetera
#   shall be deemed to be acceptance of the following conditions:-
#
#       (1) Its Recipients shall ensure that this Notice is
#       reproduced upon any copies or amended versions of it;
#
#       (2) Any amended version of it shall be clearly marked to
#       show both the nature of and the organisation responsible
#       for the relevant amendment or amendments;
#
#       (3) Its onward transfer from a recipient to another
#       party shall be deemed to be that party's acceptance of
#       these conditions;
#
#       (4) DERA gives no warranty or assurance as to its
#       quality or suitability for any purpose and DERA accepts
#       no liability whatsoever in relation to any use to which
#       it may be put.
#
+SUBSET "wint" := {
    # 7.16.1
    +TYPE ( int ) wint_t ;
    +CONST wint_t WEOF ;
} ;

+SUBSET "mse" := {
    +USE "ansi", "stdio.h" (!?) ;
    +USE "ansi", "time.h" (!?) ;

    # 7.16.1
    +IMPLEMENT "ansi", "stddef.h", "size_t" (!?) ;
    +IMPLEMENT "ansi", "stddef.h", "wchar_t" (!?) ;
    +IMPLEMENT "ansi", "stddef.h", "null" (!?) ;

    # 7.16.3.n
    +FUNC wint_t fgetwc ( FILE * ) ;
    +FUNC wchar_t *fgetws ( wchar_t *, int, FILE * ) ;
    +FUNC int fputws ( const wchar_t *, FILE * ) ;
    +FUNC wint_t getwc ( FILE * ) ;
    +FUNC wint_t getwchar ( void ) ;
    +FUNC wint_t ungetwc ( wint_t, FILE * ) ;

    # 7.16.4.1.n
    +FUNC double wcstod ( const wchar_t *, wchar_t ** ) ;
    +FUNC long wcstol ( const wchar_t *, wchar_t **, int ) ;
    +FUNC unsigned long wcstoul ( const wchar_t *, wchar_t **, int ) ;

    # 7.16.4.2.n
    +FUNC wchar_t *wcscpy ( wchar_t *, const wchar_t * ) ;
    +FUNC wchar_t *wcsncpy ( wchar_t *, const wchar_t *, size_t ) ;

    # 7.16.4.3.n
    +FUNC wchar_t *wcscat ( wchar_t *, const wchar_t * ) ;
    +FUNC wchar_t *wcsncat ( wchar_t *, const wchar_t *, size_t ) ;

    # 7.16.4.4.n
    +FUNC int wcscmp ( const wchar_t *, const wchar_t * ) ;
    +FUNC int wcscoll ( const wchar_t *, const wchar_t * ) ;
    +FUNC int wcsncmp ( const wchar_t *, const wchar_t *, size_t ) ;
    +FUNC size_t wcsxfrm ( wchar_t *, const wchar_t *, size_t ) ;

    # 7.16.4.5.n
    +FUNC size_t wcscspn ( const wchar_t *, const wchar_t * ) ;
    +FUNC size_t wcsspn ( const wchar_t *, const wchar_t * ) ;
    +FUNC size_t wcslen ( const wchar_t * ) ;
    +IFNDEF ~protect ( "cpp", "cwchar" )
    # These are overloaded in C++
    +FUNC wchar_t *wcschr ( const wchar_t *, wchar_t ) ;
    +FUNC wchar_t *wcsrchr ( const wchar_t *, wchar_t ) ;
    +FUNC wchar_t *wcspbrk ( const wchar_t *, const wchar_t * ) ;
    +ENDIF
} ;

# 7.16.1
+TYPE mbstate_t ;
+CONST wchar_t WCHAR_MAX, WCHAR_MIN ;

# 7.16.2.n
+FUNC int fwprintf ( FILE *, const wchar_t *, ... ) ;
+FUNC int fwscanf ( FILE *, const wchar_t *, ... ) ;
+FUNC int wprintf ( const wchar_t *, ... ) ;
+FUNC int wscanf ( const wchar_t *, ... ) ;
+FUNC int swprintf ( wchar_t *, size_t, const wchar_t *, ... ) ;
+FUNC int swscanf ( const wchar_t *, const wchar_t *, ... ) ;
+FUNC int vfwprintf ( FILE *, const wchar_t *, ~va_list ) ;
+FUNC int vwprintf ( const wchar_t *, ~va_list ) ;
+FUNC int vswprintf ( wchar_t *, size_t, const wchar_t *, ~va_list ) ;

# 7.16.3.n
+FUNC wint_t fputwc ( wchar_t, FILE * ) ;
+FUNC wint_t putwc ( wchar_t, FILE * ) ;
+FUNC wint_t putwchar ( wchar_t ) ;
+FUNC int fwide ( FILE *, int ) ;

# 7.16.4.5.n
+FUNC wchar_t *wcstok ( wchar_t *, const wchar_t *, wchar_t ** ) ;
+IFNDEF ~protect ( "cpp", "cwchar" )
# These are overloaded in C++
+FUNC wchar_t *wcsstr ( const wchar_t *, const wchar_t * ) ;

# 7.16.4.6.n
+FUNC wchar_t *wmemchr ( const wchar_t *, wchar_t, size_t ) ;
+ENDIF
+FUNC int wmemcmp ( const wchar_t *, const wchar_t *, size_t ) ;
+FUNC wchar_t *wmemcpy ( wchar_t *, const wchar_t *, size_t ) ;
+FUNC wchar_t *wmemmove ( wchar_t *, const wchar_t *, size_t ) ;
+FUNC wchar_t *wmemset ( wchar_t *, wchar_t, size_t ) ;

# 7.16.5
+FUNC size_t wcsftime ( wchar_t *, size_t, const wchar_t *, const struct tm * ) ;

# 7.16.6.1.n
+FUNC wint_t btowc ( int ) ;
+FUNC int wctob ( wint_t ) ;

# 7.16.6.2
+FUNC int mbsinit ( const mbstate_t * ) ;

# 7.16.6.3.n
+FUNC size_t mbrlen ( const char *, size_t, mbstate_t * ) ;
+FUNC size_t mbrtowc ( wchar_t *, const char *, size_t, mbstate_t * ) ;
+FUNC size_t wcrtomb ( char *, wchar_t, mbstate_t * ) ;

# 7.16.6.4.n
+FUNC size_t mbsrtowcs ( wchar_t *, const char **, size_t, mbstate_t * ) ;
+FUNC size_t wcsrtombs ( char *, const wchar_t **, size_t, mbstate_t * ) ;

# vim:ft=tspec:

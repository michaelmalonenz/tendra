# $TenDRA$
#
# Binary / variable definitions for the cygwin32 environment.

# The execution startup routines.
# crt is for normal support, crti for _init, crtn for _fini.
# gcrt is for profiling support (gprof).
# mcrt is for profiling support (prof).


# Libraries

LIB_CRT0?=	
LIB_CRT1?=	
LIB_CRTI?=	
LIB_CRTN?=	
LIB_GCRT0?=	
LIB_GCRT1?=	
LIB_MCRT0?=	
LIB_AOUT_CRT0?=	/usr/i486-linuxaout/lib/crt0.o
LIB_CRT0?=	/gnuwin32/b18/H-i386-cygwin32/i386-cygwin32/lib/crt0.o


# Arguments

ARGS_CP?=	
ARGS_GUNZIP?=	-f
ARGS_GZIP?=	-nf -9
ARGS_MKDIR?=	-p


# Binaries

BIN_AR?=	/bin/ar
BIN_AS?=	/gnuwin32/b18/H-i386-cygwin32/i386-cygwin32/bin/as
BIN_AWK?=	/bin/awk
BIN_BASENAME?=	/bin/basename
BIN_CAT?=	/bin/cat
BIN_CC?=	/gnuwin32/b18/H-i386-cygwin32/bin/gcc
BIN_CHGRP?=	/bin/chgrp
BIN_CHMOD?=	/bin/chmod
BIN_CHOWN?=	/bin/chown
BIN_CP?=	/bin/cp
BIN_CUT?=	/bin/cut
BIN_DC?=	/bin/dc
BIN_DIRNAME?=	/bin/dirname
BIN_ECHO?=	/bin/echo
BIN_EGREP?=	/bin/egrep
BIN_FALSE?=	/bin/false
BIN_FILE?=	/bin/file
BIN_FIND?=	/bin/find
BIN_GREP?=	/bin/grep
BIN_GTAR?=	/bin/tar
BIN_GUNZIP?=    /bin/gunzip
BIN_GZCAT?=	/bin/gzcat
BIN_GZIP?=	/bin/gzip
BIN_HEAD?=	/bin/head
BIN_ID?=	/bin/id
BIN_INSTALL?=	/usr/bin/install
BIN_LD?=	/gnuwin32/b18/H-i386-cygwin32/i386-cygwin32/bin/ld
BIN_LDCONFIG?=	echo		# non existant
BIN_LN?=	/bin/ln
BIN_LS?=	/bin/ls
BIN_MKDIR?=	/bin/mkdir
BIN_MTREE?=	echo		# non existant.
BIN_MV?=	/bin/mv
BIN_PATCH?=	/usr/bin/patch
BIN_PAX?=	echo		# non existant.
BIN_PERL?=	/bin/perl
BIN_RANLIB?=	/bin/ranlib
BIN_RM?=	/bin/rm
BIN_RMDIR?=	/bin/rmdir
BIN_SED?=	/bin/sed
BIN_RMDIR?=	/bin/rmdir
BIN_SED?=	/bin/sed
BIN_SETENV?=	/bin/env
BIN_SH?=	/bin/sh
BIN_SORT?=	/bin/sort
BIN_SU?=	/bin/su
BIN_TAIL?=	/bin/tail
BIN_TEST?=	/bin/test
BIN_TIME?=	/usr/bin/time
BIN_TOUCH?=	/bin/touch
BIN_TR?=	/bin/tr
BIN_TRUE?=	/bin/true
BIN_TYPE?=	type		# Shell builtin
BIN_WC?=	/bin/wc
XARGS?=		/bin/xargs

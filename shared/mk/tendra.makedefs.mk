# TenDRA make functions
#
# $Id$

.if !defined(_TENDRA_MAKEDEFS_MK_)
_TENDRA_MAKEDEFS_MK_=1


# Please note that blindly adding new OSes here is not enough to port TenDRA to
# a new system; the guide to porting covers the process in detail.


# We use ${UNAME} to tell us about the architecture we're building for. That
# variable may be overridden for systems with an incompatible (or no) uname(1)
# output.
#
# This is flawed in that it assumes the version of the kernel (as reported by
# uname) is the same as the version of the libraries present in /usr/include
# (as used for API building), which is not always true. However, for the rare
# situations where they differ, the user may explicitly override variables
# accordingly.
#
# In Linux's case, instead of the kernel version, we attempt to find the libc
# version; the same caveat applies.
#
# The idea here is that these variables are only assigned if required, and that
# the majority of projects do not use them (as they typically do not require
# knowledge of any particular machine). In this way we attempt to avoid
# inconveniencing the user with running a `makedefs` script per-project.


HOSTARCH!=	${UNAME} -m
SYSTEM!=	${UNAME} -s
VERSION!=	${UNAME} -r


.if ${SYSTEM} == Linux
. if (exists(/lib/libc.so.6))
GLIBC_VER!=	/lib/libc.so.6 | sed -n 's/^.* version \(.*\), .*$$/\1/p' | tr . _
. else
GLIBC_VER!=	ldd --version | sed -n 's/^ldd (GNU libc) //p' | tr . _
. endif

LIBC_VER?=	GLIBC_${GLIBC_VER}
.endif

MD_EXECFMT!=                             \
    case "${SYSTEM}" in                  \
        Darwin)    echo mach;;           \
        DragonFly) echo elf;;            \
        FreeBSD)   echo elf;;            \
        Linux)     echo elf;;            \
        NetBSD)    echo elf;;            \
        OpenBSD)   echo elf;;            \
        SunOS)     echo elf;;            \
        *)         echo unknown;;        \
    esac;

MD_BLDARCH!=                             \
    case "${HOSTARCH}" in                \
        alpha)         echo alpha;;      \
        amd64|x86_64)  echo amd64;;      \
        BePC)          echo 80x86;;      \
        i?86|i86pc)    echo 80x86;;      \
        sparc|sparc64) echo sparc;;      \
        *)             echo unknown;;    \
    esac;

MD_BLDARCHBITS!=                         \
    case "${HOSTARCH}" in                \
        alpha)        echo 64;;          \
        amd64|x86_64) echo 64;;          \
        BePC)         echo 32;;          \
        i?86|i86pc)   echo 32;;          \
        sparc)        echo 32;;          \
        sparc64)      echo 64;;          \
        *)            echo unknown;;     \
    esac;

MD_OSFAM!=                               \
    case "${SYSTEM}" in                  \
        Darwin)    echo darwin;;         \
        DragonFly) echo dragonfly;;      \
        FreeBSD)   echo freebsd;;        \
        Linux)     echo linux;;          \
        NetBSD)    echo netbsd;;         \
        OpenBSD)   echo openbsd;;        \
        SunOS)     echo solaris;;        \
        Haiku)     echo haiku;;          \
        *)         echo unknown;;        \
    esac;

MD_OSVER!=                               \
    case "${SYSTEM}.${VERSION}" in       \
        Darwin.10.3.*) echo DARWIN103;;  \
        DragonFly.1*)  echo DRAGONFLY1;; \
        FreeBSD.4*)    echo FREEBSD4;;   \
        FreeBSD.5*)    echo FREEBSD5;;   \
        FreeBSD.6*)    echo FREEBSD6;;   \
        Linux.2.4*)    echo LINUX24;;    \
        Linux.2.6*)    echo LINUX26;;    \
        NetBSD.4*)     echo NETBSD4;;    \
        NetBSD.5*)     echo NETBSD5;;    \
        OpenBSD.3*)    echo OPENBSD3;;   \
        OpenBSD.4*)    echo OPENBSD4;;   \
        SunOS.5*)      echo SUNOS5;;     \
        Haiku.1*)      echo HAIKU1;;     \
        *)             echo unknown;;    \
    esac;

MD_LIBCVER!=                             \
    case "${LIBC_VER}" in                \
        GLIBC_2_12_*) echo GLIBC2_12;;   \
        *)            echo unknown;;     \
    esac;

.endif	# !defined(_TENDRA_MAKEDEFS_MK_)

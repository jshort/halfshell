AC_INIT([halfshell], [0.1.0])
AC_CONFIG_SRCDIR([src/main.c])
AM_INIT_AUTOMAKE([foreign subdir-objects])

AC_PROG_CC
AC_PROG_CC_STDC

AC_CANONICAL_HOST

# Detect the target system
case "${host_os}" in
    linux*)
        HALFSHELL_LIBS="-lreadline"
        ;;
    darwin*)
        HALFSHELL_LIBS="-lreadline -largp"
        ;;
    *)
        AC_MSG_ERROR(["OS $host_os is not supported"])
        ;;
esac
AC_SUBST([HALFSHELL_LIBS])

AC_OUTPUT(Makefile src/Makefile)

bin_PROGRAMS = $(top_builddir)/bin/halfshell

__top_builddir__bin_halfshell_SOURCES = main.c display.c parsing.c process.c builtins.c \
					builtins/exit.c \
					builtins/pwd.c \
					builtins/cd.c \
					builtins/echo.c
__top_builddir__bin_halfshell_CFLAGS = -Wall
__top_builddir__bin_halfshell_LDADD = -lreadline -largp

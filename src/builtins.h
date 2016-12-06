#ifndef _HALFSHELL_BUILTINS_H
#define _HALFSHELL_BUILTINS_H

extern char *BUILT_IN_CMDS[];
extern int (*BUILT_IN_FUNCS[]) (char **);

int builtin_exit(char **args);
int builtin_pwd(char **args);
int builtin_cd(char **args);
int builtin_echo(char **args);

int num_builtins(void);

#endif /* _HALFSHELL_BUILTINS_H */


#include "builtins.h"

char *BUILT_IN_CMDS[] = {
                           "exit",
                           "pwd",
                           "cd",
                           "echo"
                        };

int (*BUILT_IN_FUNCS[]) (char **) = {
                                       &builtin_exit,
                                       &builtin_pwd,
                                       &builtin_cd,
                                       &builtin_echo
                                    };

int num_builtins(void)
{
  return sizeof(BUILT_IN_CMDS) / sizeof(char*);
}

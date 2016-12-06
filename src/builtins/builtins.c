#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <limits.h>

#include "../builtins.h"

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

static void print_arg(char *format, char *arg) {
  if (strcmp(arg, "$?") == 0) {
    printf("%d", errno);
  } else {
    printf(format, arg);
  }
}

int num_builtins(void)
{
  return sizeof(BUILT_IN_CMDS) / sizeof(char*);
}

int builtin_exit(char ** args)
{
  return 1;
}

int builtin_pwd(char **args)
{
  char *cur_dir = getcwd(NULL, 0);
  if (cur_dir != NULL) {
    printf("%s\n", cur_dir);
    errno = 0;
  }
  free(cur_dir);
  return 0;
}

int builtin_cd(char **args)
{
  char *dir = NULL;
  if (args[1] == NULL) {
    if (getenv("HOME") != NULL) {
      dir = getenv("HOME");
    }
  } else {
    dir = args[1];
  }
  if (dir && chdir(dir) != 0) perror("cd: ");
  else errno = 0;
  return 0;
}

int builtin_echo(char **args)
{
  int i = 2;
  if (args[1] != NULL) print_arg("%s", args[1]);
  while (args[i] != NULL) {
    print_arg(" %s", args[i]);
    ++i;
  }
  printf("\n");
  return 0;
}

#include <stdio.h>
#include <string.h>

#include "builtins.h"

static void print_args(char **args)
{
  char *arg;
  int i = 0;

  printf("Args are:\n");
  do {
    arg = args[i];
    ++i;
    printf("%s\n", arg);
  } while(arg != NULL);
}

int halfshell_process(char **args)
{
  if (args[0] == NULL) {
    return 0;
  }

  for (int i = 0; i < num_builtins(); ++i) {
    if (strcmp(args[0], BUILT_IN_CMDS[i]) == 0) {
      return (*BUILT_IN_FUNCS[i])(args);
    }
  }

  print_args(args);
  return 0;
}

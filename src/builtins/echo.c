#include <errno.h>
#include <stdio.h>
#include <string.h>

static void print_arg(char *format, char *arg) {
  if (strcmp(arg, "$?") == 0) {
    printf("%d", errno);
  } else {
    printf(format, arg);
  }
}

int builtin_echo(char **args)
{
  int i = 2;
  if (args[1] != NULL) {
    print_arg("%s", args[1]);
    while (args[i] != NULL) {
      print_arg(" %s", args[i]);
      ++i;
    }
  }
  printf("\n");
  return 0;
}

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
  if (dir && chdir(dir) != 0) fprintf(stderr, "%s: %s: %s\n", "cd", args[1], strerror(errno));
  else errno = 0;
  return 0;
}


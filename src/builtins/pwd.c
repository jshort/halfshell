#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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


#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#include "builtins.h"
#include "constants.h"

static void execute_command(char **args) {
  pid_t cpid, wait_pid;
  int wstatus;

  cpid = fork();
  if (cpid == -1) {
    /* error, in parrent */
    perror(PERROR_PREFIX);
  } else if (cpid == 0) {
    /* success, in child */
    /* execvp doesn't return on success so handle accordingly */
    if (execvp(args[0], args) == -1) perror(PERROR_PREFIX);
    exit(EXIT_FAILURE);
  } else {
    /* success, in parent */
    do {
      wait_pid = waitpid(cpid, &wstatus, WUNTRACED | WCONTINUED);
    } while (!WIFEXITED(wstatus) && !WIFSIGNALED(wstatus));
    errno = WEXITSTATUS(wstatus);
  }
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

  execute_command(args);

  return 0;
}

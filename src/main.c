#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* #include <termios.h> */
#include <unistd.h>

#include "parsing.h"
#include "process.h"
#include "display.h"

void halfshell_run(int argc, char **argv)
{
  int should_exit = 0;
  char *prompt, *line, **input_args;
  /* static struct termios old_term, new_term; */

  /* Configure terminal for no bufferring */
  /* tcgetattr( STDIN_FILENO, &old_term); */
  /* new_term = old_term; */
  /* new_term.c_lflag &= ~(ICANON); */
  /* tcsetattr(STDIN_FILENO, TCSANOW, &new_term); */

  print_turtle();

  while (!should_exit) {
    prompt = get_prompt();
    line = read_input(prompt);
    /* printf("line is: h%sh\n", line); */
    /* printf("line size: %d\n", strlen(line)); */
    input_args = tokenize_input(line);
    /* printf("arg[0] is: %s\n", input_args[0]); */
    should_exit = halfshell_process(input_args);

    free(line);
    free(input_args);
  }

  /* Reset terminal */
  /* tcsetattr(STDIN_FILENO, TCSANOW, &old_term); */
}

int main(int argc, char **argv)
{
  halfshell_run(argc, argv);
  return EXIT_SUCCESS;
}

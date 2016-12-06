#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parsing.h"
#include "process.h"
#include "display.h"

void halfshell_run(int argc, char **argv)
{
  int should_exit = 0;
  char *line, **input_args;

  print_turtle();

  while (!should_exit) {
    print_prompt();
    line = read_input();
    input_args = tokenize_input(line);
    should_exit = halfshell_process(input_args);

    free(line);
    free(input_args);
  }
}

int main(int argc, char **argv)
{
  halfshell_run(argc, argv);
  return EXIT_SUCCESS;
}

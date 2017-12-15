#include <argp.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "parsing.h"
#include "process.h"
#include "display.h"

/* ##### argp parsing logic for main executable ################################### */
#define CLI_VERSION_KEY 777
#define SHORT_USAGE (ARGP_HELP_SHORT_USAGE | ARGP_HELP_EXIT_ERR)

const char *argp_program_bug_address =
  "james.short@alumni.duke.edu";

static const char *APP_VERSION = "0.1";

static const char *HELP_FMT =
  "no-dup-args-note,short-opt-col=4,long-opt-col=8";

/* Program documentation. */
static const char *DOC =
  "Basic Unix shell.\v"
  "See README.md for future features.";

typedef struct {
  char *command;
  int silent;
} ARGUMENTS;

static const struct argp_option options[] = {
  {0,0, 0, 0, "Program Options:", 5 },
  {"command",  'c', "COMMAND",  0,  "Execute command and exit" },
  {"silent",   's', 0,          0,  "Don't produce any output" },
  {0,          'q', 0,          OPTION_ALIAS },
  { 0, 0, 0, 0, "General Options:", -1 },
  {"help",     'h',             0,      0,  "This help menu"},
  {"version",  CLI_VERSION_KEY, 0,      0,  "Print program version"},
  {0}
};

static error_t parse_opt (int key, char *arg, struct argp_state *state)
{
  /* Get the input argument from argp_parse, which we
     know is a pointer to the arguments structure. */
  ARGUMENTS *arguments = state->input;

  switch (key)
  {
    case 'q':
    case 's':
      arguments->silent = 1;
      break;
    case 'c':
      arguments->command = arg;
      break;
    case 'h':
      argp_state_help (state, state->out_stream, ARGP_HELP_STD_HELP);
    case CLI_VERSION_KEY:
      fprintf (state->out_stream, "%s\n", APP_VERSION);
      exit(0);
    case ARGP_KEY_ARG:
      fprintf (state->out_stream, "%s\n", "*** Too many arguments ***");
      argp_err_exit_status = 1;
      argp_state_help (state, state->out_stream,
                       SHORT_USAGE);
    default:
      return ARGP_ERR_UNKNOWN;
  }
  return 0;
}
/* ################################################################################ */

static void interactive_run(void)
{
  int should_exit = 0;
  char *prompt, *command, **input_args;

  print_turtle();

  do {
    prompt = get_prompt();
    command = read_input(prompt);
    input_args = tokenize_input(command);
    should_exit = halfshell_process(input_args);

    free(command);
    free(input_args);
  } while (!should_exit);
}

static void noninteractive_run(ARGUMENTS arguments)
{
  char **input_args;
  char *command = arguments.command;
  input_args = tokenize_input(command);
  halfshell_process(input_args);
  exit(errno);
}

static void halfshell_run(int argc, char **argv)
{
  struct argp argp = {options, parse_opt, NULL, DOC};
  /* Customize help output */
  setenv("ARGP_HELP_FMT", HELP_FMT, 0);

  ARGUMENTS arguments = {NULL, 1};

  argp_parse(&argp, argc, argv, ARGP_NO_HELP, 0, &arguments);

  /* Non-interactive execution of command */
  if (arguments.command) noninteractive_run(arguments);

  /* Interactive shell */
  interactive_run();
}

int main(int argc, char **argv)
{
  halfshell_run(argc, argv);
  return EXIT_SUCCESS;
}

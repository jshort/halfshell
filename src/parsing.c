#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "parsing.h"

#define LINE_BUFFER_SIZE 128
#define TOKEN_COUNT 16
#define TOKEN_DELIMITERS " \r\n\t\v\f"

void strip_newline(char *s, size_t len)
{
  if (s[len - 1] == '\n') {
    s[len - 1] = '\0';
  }
}

char *read_input(char *prompt)
{
  char *line;
  line = readline(prompt);
  if (line && *line) {
    add_history(line);
  }
  return line;
}

char *read_input_char(void)
{
  int line_length = LINE_BUFFER_SIZE;
  char *line = malloc(line_length * sizeof(char));
  int i = 0;
  char cur_char;

  if (line == NULL) {
    perror("Could not allocate input line");
    exit(EXIT_FAILURE);
  }

  while(1) {
    cur_char = getchar();

    /* printf("%c\n", cur_char); */
    if (cur_char == '\033') {
      getchar();
      switch(getchar()) {
        case 'A':
          printf("Up arrow\n");
          break;
        case 'B':
          printf("Down arrow\n");
          break;
      }
      cur_char = '\0';
    }

    if (cur_char == '\n' || cur_char == EOF) {
      line[i] = '\0';
      return line;
    } else {
      line[i] = cur_char;
    }
    ++i;
  }
}

char **tokenize_input(char *input)
{
  int i = 0;
  int token_count = TOKEN_COUNT;
  char **tokens = malloc(token_count * sizeof(char*));
  char *saveptr = NULL, *token = NULL;

  if (tokens == NULL) {
    perror("Could not allocate tokens");
    exit(EXIT_FAILURE);
  }

  while ((token = strtok_r(!i ? input : NULL, TOKEN_DELIMITERS, &saveptr))) {
    tokens[i] = token;
    ++i;
    /* Need to expand tokens */
    if (i >= token_count) {
      token_count *= 2;
      tokens = realloc(tokens, token_count * sizeof(char*));
      if (tokens == NULL) {
        perror("Could not allocate tokens");
        exit(EXIT_FAILURE);
      }
    }
  }
  tokens[i] = NULL;
  return tokens;
}

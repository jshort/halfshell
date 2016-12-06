#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parsing.h"

#define TOKEN_BUFFER_SIZE 32
#define TOKEN_DELIMITERS " \r\n\t\v\f"

void strip_newline(char *s, size_t len)
{
  if (s[len - 1] == '\n') {
    s[len - 1] = '\0';
  }
}

char *read_input(void)
{
  char *buffer = NULL;
  size_t linesize = 0;
  size_t char_count;

  char_count = getline(&buffer, &linesize, stdin);
  strip_newline(buffer, char_count);

  return buffer;
}

char **tokenize_input(char *input)
{
  size_t token_buffer_size = TOKEN_BUFFER_SIZE;
  int i = 0;
  char **tokens = malloc(token_buffer_size * sizeof(char*));
  char *saveptr = NULL, *token = NULL;

  if (tokens == NULL) {
    perror("Could not allocate tokens");
    exit(1);
  }

  while ((token = strtok_r(!i ? input : NULL, TOKEN_DELIMITERS, &saveptr))) {
    tokens[i] = token;
    ++i;
  }
  tokens[i] = NULL;
  return tokens;
}

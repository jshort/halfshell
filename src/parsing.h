#ifndef _HALFSHELL_PARSING_H
#define _HALFSHELL_PARSING_H

void strip_newline(char *s, size_t len);
char *read_input(char *prompt);
char *read_input_char(void);
char **tokenize_input(char *input);

#endif /* _HALFSHELL_PARSING_H */

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_PROMPT "halfshell > "

void print_prompt(void)
{
  char *PS1 = DEFAULT_PROMPT;
  /* char *PS1 = (getenv("PS1") == NULL ? DEFAULT_PROMPT : getenv("PS1")); */
  printf("%s", PS1);
}

void print_turtle(void)
{

  const char *welcome = "                             ___-------___\n"
                        "                         _-~~             ~~-_\n"
                        "                      _-~                    /~-_\n"
                        "   /^__/^\\         /~  \\                   /    \\\n"
                        " /|  O|| O|        /      \\_______________/        \\\n"
                        "| |___||__|      /       /                \\          \\\n"
                        "|          \\    /      /                    \\          \\\n"
                        "|   (_______) /______/                        \\_________ \\\n"
                        "|         / /         \\                      /            \\\n"
                        " \\         \\^\\\\         \\                  /               \\     /\n"
                        "   \\         ||           \\______________/      _-_       //\\__//\n"
                        "     \\       ||------_-~~-_ ------------- \\ --/~   ~\\    || __/\n"
                        "       ~-----||====/~     |==================|       |/~~~~~\n"
                        "        (_(__/  ./     /                    \\_\\      \\.\n"
                        "               (_(___/                         \\_____)_)\n";
  printf("%s\n", welcome);

}

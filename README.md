# halfshell
Linux terminal shell

## Objective
This is a project is a simple terminal shell written in ANSI C.  Its name is due to a turtle theme (TMNT).
I'm not entirely sure how far I will take it but I will write up more documentation if it becomes more than
a pet project (no pun intended).

### Features
* Builtins: cd, pwd, echo, exit.
* Execute system commands and set exit code in $? accordingly.
* echo last command exit status.
* Read PS1 env var for setting prompt.
* Up/down history integreation via lib readline.
* Help menu for shell executable and inline command execution.

### TODO
* Generic string interpolation ("$var" => "Value in variable var").
* rc/config file support (.halfshellrc).
* Special parameters ($$, $?, $#, $@, etc).
* Help menus for builtins (need to integrate argp).

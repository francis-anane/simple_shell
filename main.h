#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#include <stdarg.h>

int _putchar(char c);
char *get_cmd();
char **get_args(char *args_str);
char *get_args_str(char *c_str);
char *get_cmd_file(char *cmd_str);
void cmdl_arg(int ac, int c_count, char **av);
char *get_path(char *exe);
void creat_ps(char *path, char **av, char **env, int c);
void _cd(char *dir, char *sh, int c);
#endif

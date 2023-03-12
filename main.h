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

char *get_cmd(int *rd);
char **get_args(char *args_str);
void cmdl_arg(int ac, int c, char **av);
char *get_path(char *exe);
void creat_ps(char *path, char **av, char **env, char *cmdfile, int c);
void _cd(char *dir, char *sh, int c);
char *_arg0(char *c_file);
char *_cmdfile(char *cmd_str);
int free_arr(char **arr);
void free_mem(const unsigned int n, ...);
#endif

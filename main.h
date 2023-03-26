#ifndef MAIN_H
#define MAIN_H
/*#define _GNU_SOURCE*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <dirent.h>
#include <string.h>

int _unset(char *cmd_str, __attribute__((unused)) char **path);
void _print(const unsigned int n, ...);
int _putchar(char c);
void print_number_err(int n);
void _print_err(const unsigned int n, ...);
char *from_lindex(char *str, char delim);
char *after_lindex(char *str, char delim);
char *from_findex(char *str, char delim);
char *after_findex(char *str, char delim);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *str1, char *str2);
int array_size(char **arr);
int token_count(char *str, const char delim);
char *get_cmd(int *rd);
char **get_args(char *args_str, char *arg0);
void cmdl_arg(int ac, char **av, int c);
char *get_path(char *exe, char *paths, int *st);
void new_ps(char *sh, char *p, char **av, char **ev, char *cf, int c, int *s);
void _cd(char *dir, char *sh, int c, int *st);
char *_arg0(char *c_file);
char *_cmdfile(char *cmd_str);
int free_arr(char **arr);
void free_mem(const unsigned int n, ...);
int string_len(char *str);
char *string_dup(char *str);
void _term(char *cmd, int *st);
void _putchar_err(char c);
int in_cdir(char *cfile);
int is_dir(char *path);
int cdir_exec(char *cfile, int *st);
int _env(char *cmd, char **env);

#endif

#ifndef MAIN_H
#define MAIN_H
int _putchar(char c);
char *get_cmd();
char **get_args(char *args_str);
char *get_args_str(char *c_str);
char *get_cmd_file(char *cmd_str);
void cmdl_arg(int ac, int c_count, char **av);
#endif

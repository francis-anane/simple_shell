#include "main.h"

/**
 * _cd - Change directory
 * @dir: The directory to change to
 * @sh: The commandline shell that is running.
 * @c: Number of entered commands in the shell.
 * @s: Pointer to exit status
 */

void _cd(char *dir, char *sh, int c, int *s)
{
	int rt;

	rt = chdir(dir);
	if (rt < 0)
	{
		_print_err(2, sh, ": ");
		print_number_err(c);
		_print_err(3, ": cd: can't cd to ", dir, "\n");
		*s = 2;
	}
}

/**
 * _term - Exit a proccess
 * @cmd: A pointer to a memory to free
 * @cmd_cp: A pointer to a memory to free
 * @path: memory to free
 * @argv: A pointer to a malloc allocated array of strings.
 */

void _term(char *path, char *cmd, char *cmd_cp, char **argv, int *s)
{
	free_mem(3, path, cmd, cmd_cp);
	free_arr(argv);
	exit(*s);
}

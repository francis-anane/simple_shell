#include "main.h"

/**
 * _cd - Change directory
 * @dir: The directory to change to
 * @sh: The commandline shell that is running.
 * @c: Number of entered commands in the shell.
 */

void _cd(char *dir, char *sh, int c)
{
	int rt;

	rt = chdir(dir);
	if (rt < 0)
	{
		_print_err(2, sh, ": ");
		print_number_err(c);
		_print_err(3, ": cd: can't cd to ", dir, "\n");
	}
}

/**
 * _term - Exit a proccess
 * @cmd_cp: A pointer to a memory to free
 * @path: memory to free
 * @argv: A pointer to a malloc allocated array of strings.
 */

void _term(char *cmd_cp, char *path, char **argv)
{
	free_mem(2, cmd_cp, path);
	free_arr(argv);
	exit(0);
}

#include "main.h"

/**
 * _cd - Change directory
 * @dir: The directory to change to
 * @sh: The commandline shell that is running.
 * @c: Number of entered commands in the shell.
 */

void _cd(char *dir)
{
	int rt;

	rt = chdir(dir);
	if (rt < 0)
		perror("hsh ");
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

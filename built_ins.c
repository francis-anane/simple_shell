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

/**
 * _unset - Unset environment variable of the shell executions path
 * @cmd_str: command string
 * @path: Pointer to the executions path.
 * Return: 0 on success, -1 on failure
 */

int _unset(char *cmd_str, __attribute__((unused)) char **path)
{
	int ret = -1;
	if (_strcmp(cmd_str, "unset PATH") == 0)
	{
		*path = "\0";
		free(cmd_str);
		ret = 0;
	}
	return (ret);
}

/**
 * shell_built_ins - Call built in functions
 * @cmd: The command
 * @arg: Argument to command
 * @path: Pointer to the command file path string.
 *
 */

#include "main.h"

/**
 * _cd - Change directory
 * @dir: The directory to change to
 * @sh: Pointer to the program name string
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
 * @s: Pointer to exit status.
 */

void _term(char *cmd, int *s)
{
	free(cmd);
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

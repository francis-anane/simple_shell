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
	if (_strcmp(cmd, "exit") == 0)
	{
		free(cmd);
		exit(*s);
	}
}

/**
 * _unset - Unset environment variable of the shell executions path
 * @cmd_str: command string
 * @path: Pointer to the executions path.
 * Return: 0 (condition is true), -1 (condition is false)
 */

int _unset(char *cmd_str, __attribute__((unused)) char **path)
{

	if (_strcmp(cmd_str, "unset PATH") == 0)
	{
		*path = "\0";
		free(cmd_str);
		return (0);
	}
	return (-1);
}

/**
 * _env - Implements built-in function env.
 * @cmd: The command
 * @env: Pointer to array of environment arguments
 *
 * Return: 0 (condition is true), -1 (condition is false)
 */

int _env(char *cmd, char **env)
{
	int i;

	if (_strcmp(cmd, "env") == 0)
	{
		i = 0;
		while (env[i] != NULL)
		{
			_print(1, env[i]);
			i++;
		}
		_print(1, "\n");
		free(cmd);
		return (0);
	}
	return (-1);
}

#include "main.h"

/**
 * main - entry point
 *
 * Description: A simple shell program to execute commands
 * @ac: Argument count
 * @av: Argument vector
 * @env: Environment argument
 * Return: 0 (success)
 */

int main(int ac, char **av, char **env)
{
	char *cmd, *cmd_cp, *cmd_file, *path, **argv, *arg0;
	int rd = 0, c = 0;

	cmdl_arg(ac, av, c);
	while (1)
	{
		c++;
		cmd = get_cmd(&rd);
		if (rd == EOF)
			break;
		cmd_cp = string_dup(cmd);
		cmd_file = _cmdfile(cmd_cp);
		if (cmd_file == NULL)
		{
			free_mem(2, cmd_cp, cmd);
			continue;
		}
		path = get_path(cmd_file);
		arg0 = _arg0(cmd_file);
		argv = get_args(cmd, arg0);
		free(cmd);
		if (_strcmp(path, "exit") == 0)
			_term(path, cmd_cp, argv);
		else if (_strcmp(path, "cd") == 0)
			_cd(argv[1], av[0], c);
		else
			creat_ps(path, argv, env, cmd_file, c);

		free_mem(2, path, cmd_cp);
		free_arr(argv);
	}
	write(STDERR_FILENO, "\n", 1);
	return (0);
}

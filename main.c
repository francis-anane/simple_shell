#include "main.h"

/**
 * main - entry point.
 *
 * Description: A simple shell program to execute commands
 * @ac: Argument count
 * @av: Argument vector
 * @env: Environment argument
 * Return: 0 (success)
 */

int main(int ac, char **av, char **env)
{
	char *cmd, **argv, *arg_str, *cm_str, *path;
	int c = 0;

	cmdl_arg(ac, c, av);

	while (1)
	{
		cmd = get_cmd();
		cm_str = get_cmd_file(cmd);
		path = get_path(cm_str);
		arg_str = get_args_str(cmd);
		argv = get_args(arg_str);
		if (strcmp(path, "cd") == 0)
			_cd(argv[1], av[0], c);
		else if (strcmp(path, "exit") == 0)
			exit(0);
		else
		{
			creat_ps(path, argv, env, c);
			free(path);
			free(arg_str);
			free(argv);
		}

		if (isatty(STDIN_FILENO) != 1)
			exit(0);
	}
	free(cm_str);
	free(arg_str);
	free(argv);
	return (0);
}

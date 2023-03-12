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
	char *cmd, *cmd_cp, *cmd_file, *path, **argv;
	int c = 0, rd = 0;

	cmdl_arg(ac, c, av);
	while (rd != EOF)
	{
		c++;
		cmd = get_cmd(&rd);
		cmd_cp = strdup(cmd);
		cmd_file = _cmdfile(cmd_cp);
		if (cmd_file == NULL)
		{
			free_mem(2, cmd, cmd_cp);
			continue;
		}
		path = get_path(cmd_file);
		argv = get_args(cmd);
		free(cmd);
		if (strcmp(path, "exit") == 0)
		{
			free_mem(2, path, cmd_cp);
			free_arr(argv);
			exit(127);
		}
		if (strcmp(path, "cd") == 0)
			_cd(argv[1], av[0], c);
		else
		{
			if (access(path, F_OK) == 0)
				creat_ps(path, argv, env, cmd_file, c);
			else
				printf("hsh: %d: %s: not found\n", c, argv[0]);
		}
		free_mem(2, path, cmd_cp);
		free_arr(argv);
	}
	return (0);
}

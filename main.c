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
	char *cmd, *cmd_cp, *path, **argv;
	int c = 0, rd = 0;

	cmdl_arg(ac, c, av);
	while (rd != EOF)
	{
		c++;
		cmd = get_cmd(&rd);
		cmd_cp = strdup(cmd);
		if ((strtok(cmd_cp, " ")) == NULL)
		{
			free(cmd);
			free(cmd_cp);
			continue;
		}
		argv = get_args(cmd);
		path = get_path(argv[0]);
		free(cmd);
		free(cmd_cp);
		if (strcmp(path, "exit") == 0)
		{
			free(path);
			free_arr(argv);
			break;
		}
		if (strcmp(path, "cd") == 0)
			_cd(argv[1], av[0], c);
		else
		{
			if (access(path, F_OK) == 0)
				creat_ps(path, argv, env, c);
			else
				printf("hsh: %d: %s: not found\n", c, argv[0]);
		}
		free(path);
		free_arr(argv);
	}
	printf("\n");
	exit(0);
}

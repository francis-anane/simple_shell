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
	char *cmd, *cmd_file, *cmd_cp, *path, **argv;
	int c = 0, rd = 0;

	cmdl_arg(ac, c, av);
	if (isatty(STDIN_FILENO) != 1)
		piped_cmd(av, env);

	while (rd != EOF)
	{
		c++;
		cmd = get_cmd(&rd);
		cmd_cp = strdup(cmd);
		cmd_file = get_cmd_file(cmd);
		path = get_path(cmd_file);
		if (path == NULL)
		{
			free(cmd_cp);
			continue;
		}
		argv = get_args(cmd_cp);
		free(cmd_cp);
		if (strcmp(path, "cd") == 0)
			_cd(argv[1], av[0], c);

		else if (strcmp(path, "exit") == 0)
		{
			free_arr(argv);
			exit(0);
		}
		else
		{
			if (access(path, F_OK) == 0)
				creat_ps(path, argv, env);
			else
			{
				printf("hsh: %d: %s: not found\n", c, argv[0]);
			}

		}
		free_arr(argv);
	}
	printf("\n");
	return (0);
}

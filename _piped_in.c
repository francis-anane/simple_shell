#include "main.h"

/**
 * piped_cmd - Execute piped commands.
 * @av: argument vector
 * @env: environment argument
 */
void piped_cmd(char **av, char **env)
{
	char *cmd, *cmd_file, *cmd_cp, *path, **argv, *buff;
	int rd, c = 0;
	size_t n;

	rd = getline(&buff, &n, stdin);
	while (rd != EOF)
	{
		c++;
		cmd = strsep(&buff, "\n");

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
			printf("\n");
		else
		{
			if (access(path, F_OK) == 0)
				creat_ps(path, argv, env);
			else
				printf("hsh: %d: %s: not found\n", c, argv[0]);
		}
		rd = getline(&buff, &n, stdin);

	}
	free(argv);
	exit(0);
}

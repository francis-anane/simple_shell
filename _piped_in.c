#include "main.h"

/**
 * piped_cmd - Execute piped commands.
 * @av: argument vector
 * @env: environment argument
 */
void piped_cmd(char **av, char **env)
{
	char *cmd, *cmd_cp, *path, **argv, *buff = NULL;
	int rd, c = 0;
	size_t n;

	if (isatty(STDIN_FILENO) == 1)
		return;
	rd = getline(&buff, &n, stdin);
	while (rd != EOF)
	{
		c++;
		cmd = strtok(buff, "\n");
		cmd_cp = strdup(cmd);
		if ((strtok(cmd_cp, " ")) == NULL)
		{
			free(cmd_cp);
			rd = getline(&buff, &n, stdin);
			continue;
		}
		argv = get_args(cmd);

		path = get_path(argv[0]);
		if (strcmp(path, "cd") == 0)
			_cd(argv[1], av[0], c);
		else if (strcmp(path, "exit") == 0)
			printf("\n");
		else
		{
			if (access(path, F_OK) == 0)
				creat_ps(path, argv, env, c);
			else
				printf("hsh: %d: %s: not found\n", c, argv[0]);
		}
		free(cmd_cp);
		free(path);
		free_arr(argv);
		rd = getline(&buff, &n, stdin);

	}
	exit(0);
}

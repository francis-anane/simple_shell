#include "main.h"

/**
 * get_path - Get a path for a commandline executable
 * @exe: The commandline file to get path for.
 * Return: A pointer to the path
 */

char *get_path(char *exe)
{
	char **path, *exe_p, *tok, *cmd_str, *cmd;
	int i, j, k;

	path = malloc(sizeof(char *) * 8);
	if (path == NULL)
		return (NULL);
	exe_p = getenv("PATH");
	tok = strtok(exe_p, ":");
	i = 0;
	while (tok != NULL)
	{
		j = 0;
		path[i] = malloc((strlen(tok) + 2) * sizeof(char));
		if (path[i] == NULL)
			return (NULL);
		for (; j < strlen(tok); j++)
			path[i][j] = tok[j];
		path[i][j] = '/';
		path[i][j + 1] = '\0';

		tok = strtok(NULL, ":");
		i++;
	}
	i = 0;
	while (i < 8)
	{
		cmd_str = strcat(path[i], exe);
		if (access(cmd_str, F_OK)  == 0)
		{
			cmd = malloc(sizeof(char *));
			for (k = 0; k < strlen(cmd_str); k++)
				cmd[k] = cmd_str[k];
			cmd[k] = '\0';
			return (cmd);
		}
		i++;
	}
	free(path);
	return (exe);
}

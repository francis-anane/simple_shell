#include "main.h"

/**
 * get_path - Get a path for a commandline executable.
 * @exe: The commandline file to get path for.
 * Return: A pointer to a malloc alloca the path
 */

char *get_path(char *exe)
{
	char *paths, *paths_cp, *exe_path, *path_tok;
	int tok_len, exe_len;

	/* get path of shell executables*/
	if (exe == NULL)
		return (NULL);
	paths = getenv("PATH");
	paths_cp = string_dup(paths);
	/*allocate memory to store executable path by computing size as needed*/
	path_tok = strtok(paths_cp, ":");
	exe_len = string_len(exe);
	while (path_tok != NULL)
	{
		tok_len = string_len(path_tok);
		exe_path = malloc(exe_len + tok_len + 2);

		if (exe_path == NULL)
		{
			free(paths_cp);
			return (NULL);
		}
		/*creat command path by appending input to path*/
		_strcpy(exe_path, path_tok);
		_strcat(exe_path, "/");
		_strcat(exe_path, exe);
		_strcat(exe_path, "\0");
		if (access(exe_path, F_OK) == 0)
		{
			free(paths_cp);
			return (exe_path);
		}
		else
			free(exe_path);
		path_tok = strtok(NULL, ":");
	}
	free(paths_cp);
	exe_path = string_dup(exe);
	return (exe_path);
}

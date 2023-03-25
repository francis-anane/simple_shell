#include "main.h"

/**
 * is_dir - check if command is a directory
 * @path: Pointer to command file
 * Return: 0 (command is executable file), or 1 (is a directory)
 */

int is_dir(char *path)
{
	DIR *dir;

	dir = opendir(path);
	if (dir == NULL)
		return (0);
	closedir(dir);
	return (1);
}

/**
 * in_cdir - check if file is in current dorectory
 * @cfile: A pointer  to the command file string.
 * Return: 0 (file is not in cwd), or 1 (file is in cwd).
 */

int in_cdir(char *cfile)
{
	char *buff = NULL, *cdir;
	size_t size = 1024;

	cdir = getcwd(buff, size);
	_strcat(cdir, "/");
	_strcat(cdir, cfile);

	if (access(cdir, F_OK) == 0)
	{
		free(cdir);
		return (1);
	}
	free(cdir);
	return (0);
}

#include "main.h"

/**
 * cdir_exec - set execution permission from current directory.
 * @exefile: executable file
 * @exec_perm: execution permission
 *
 * Return: 1 (granted), 0 (not granted).
 */

int cdir_exec(char *exefile, int *exec_perm)
{
	char *buff = NULL, *curdir;
        size_t n = 1024;

	*exec_perm = 1;
	curdir = getcwd(buff, n);
	_strcat(curdir, "/");
	_strcat(curdir, exefile);
	if ((access(curdir, F_OK) == 0) && (from_lindex(curdir, '.') == NULL))
		*exec_perm = 0;
	free(curdir);

	return (*exec_perm);
}

#include "main.h"

/**
 * _cd - Change directory
 * @dir: The directory to change to
 * @sh: The commandline shell that is running.
 * @c: Number of entered commands in the shell.
 */

void _cd(char *dir, char *sh, int c)
{
	int rt;

	rt = chdir(dir);
	if (rt < 0)
		printf("%s: %d: cd: can't cd to %s\n", sh, c, dir);
}

#include "main.h"

/**
 * cdir_exec - Check execution inside current working directory.
 * @cfile: Pointer to the command file string.
 * @st: Pointer to program exit status.
 * Return: 0, if absolute path is not given or 1 (absolute path give)
 */

int cdir_exec(char *cfile, int *st)
{
	char *chk;

	if (in_cdir(cfile) == 1)
	{
		chk = after_findex(cfile, '.');
		if (chk == NULL)
		{
			*st = 127;
			return (0);
		}
		else
		{
			if (*chk != '/')
			{
				*st = 127;
				return (0);
			}
		}
	}
	return (1);
}

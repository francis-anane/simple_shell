#include "main.h"

/**
 * new_ps - Creat a child process
 * @sh: Program name param for error output
 * @p: Path for the executable
 * @av: Arguments for the execve call
 * @ev: Envronment Arguments for the execve call.
 * @cf: Pointer to the command file
 * @c: commands count
 * @s: pointer to programs excution status.
 */

void creat_ps(char *sh, char *p, char **av, char **ev, char *cf, int c, int *s)
{
	int pid, status, ret;
	DIR *dir;

	/*char *buff = NULL, *curdir;
	  size_t n = 1024;*/

	/*curdir = getcwd(buff, n);
	_strcat(curdir, "/");
	_strcat(curdir, cf);
	printf("%s\n", curdir);*/

	if ((access(p, F_OK) == 0) && (*s == 1))
	{
		dir = opendir(p);
		if (dir != NULL)
		{
			closedir(dir);
			_print_err(2, sh, ": ");
			print_number_err(c);
			_print_err(2, ": ", cf);
			_print_err(1, ": permission denied\n");
			*s = 126;
		}
		else
		{
			pid = fork();
			if (pid == 0)
				execve(p, av, ev);
			ret = waitpid(pid, &status, 0);
			if (ret == pid)
				*s = 0;
		}
	}
	else
	{
		_print_err(2, sh, ": ");
		print_number_err(c);
		_print_err(2, ": ", cf);
		_print_err(1, ": not found\n");
		*s = 127;
	}
}

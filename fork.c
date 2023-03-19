#include "main.h"

/**
 * creat_ps - Creat a child process
 * @sh: Program name for error output
 * @p: Path for the executable
 * @av: Arguments for the process
 * @ev: Envronment Arguments for the process.
 * @cf: Pointer to the command file
 * @c: commands count
 * @s: pointer to exit status number
 */

void creat_ps(char *sh, char *p, char **av, char **ev, char *cf, int c, int *s)
{
	int pid, status, ret;
	DIR *dir;

	if (access(p, F_OK) == 0)
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

#include "main.h"

/**
 * new_ps - Creat a child process
 * @sh: Program name param for error output
 * @p: Path for the executable
 * @av: Arguments for the execve call
 * @ev: Envronment Arguments for the execve call.
 * @cf: Pointer to the command file
 * @c: commands count
 * @s: pointer to process exit status.
 */

void new_ps(char *sh, char *p, char **av, char **ev, char *cf, int c, int *s)
{
	int pid, status;

	if (is_dir(p) == 1)
		*s = 126;
	if (*s == 0)
	{
		pid = fork();
		if (pid == 0)
			execve(p, av, ev);
		waitpid(pid, &status, 0);
	}
	if (*s == 127)
	{
		_print_err(2, sh, ": ");
		print_number_err(c);
		_print_err(3, ": ", cf, ": not found\n");
	}
	if (*s == 126)
	{
		_print_err(2, sh, ": ");
		print_number_err(c);
		_print_err(3, ": ", cf, ": permission denied\n");
	}
}

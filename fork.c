#include "main.h"

/**
 * creat_ps - Creat a child process
 * @path: Path for the executable
 * @av: Arguments for the process
 * @env: Envronment Arguments for the process.
 * @cmdfile: Pointer to the command file
 * @c: commands count
 */

void creat_ps(char *path, char **av, char **env, char *cmdfile, int c)
{
	int pid, status;
	DIR *dir;

	if (access(path, F_OK) == 0)
	{
		if ((dir = opendir(path)) != NULL)
		{
			closedir(dir);
			_print_err(1, "hsh: ");
			print_number_err(c);
			_print_err(2, ": ", cmdfile);
			_print_err(1, ": permission denied\n");
		}
		else
		{
			pid = fork();
			if (pid == 0)
				execve(path, av, env);
			waitpid(pid, &status, 0);
		}
	}
	else
	{
		_print_err(1, "hsh: ");
		print_number_err(c);
		_print_err(2, ": ", cmdfile);
		_print_err(1, ": not found\n");
	}
}

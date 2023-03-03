#include "main.h"

/**
 * creat_ps - Creat a child process
 * @path: Path for the executable.
 * @av: Arguments for the process
 * @env: Envronment Arguments for the process.
 * @c: commands count
 */

void creat_ps(char *path, char **av, char **env, int c)
{
	int pid, status, ret, cpid;

	pid = fork();

	if (pid == 0)
	{
		execve(path, av, env);
		cpid = getpid();
	}

	ret = waitpid(pid, &status, 0);
	if (ret != pid)
	{
		if (av[0] != NULL)
			printf("hsh: %d: %s: not found\n", c, av[0]);
		/*Terminate child*/
		kill(cpid, SIGTERM);
	}
}

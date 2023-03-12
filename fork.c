#include "main.h"

/**
 * creat_ps - Creat a child process
 * @path: Path for the executable.
 * @av: Arguments for the process
 * @env: Envronment Arguments for the process.
 * @cmdfile: Pointer to the command file
 * @c: commands count
 */

void creat_ps(char *path, char **av, char **env, char *cmdfile, int c)
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
			printf("hsh: %d: %s: Permission denied\n", c, cmdfile);
		/*Terminate child*/
		kill(cpid, SIGTERM);
	}
}

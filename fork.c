#include "main.h"

/**
 * creat_ps - Creat a child process
 * @path: Path for the executable
 * @av: Arguments for the process
 * @env: Envronment Arguments for the process.
 * @cmdfile: Pointer to the command file
 * @c: commands count
 */

void creat_ps(char *path, char **av, char **env)
{
	int pid, status, ret, cpid;
	/*struct stat *buff;*/

	if (access(path, F_OK) == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			execve(path, av, env);
			cpid = getpid();
		}
		ret = waitpid(pid, &status, 0);
		if (ret != pid)
		{
			perror(av[0]);
			kill(cpid, SIGTERM);
		}
	}
	else
	{
		perror("hsh ");
	}
}

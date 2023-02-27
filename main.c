#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
/**
 * main - entry point.
 *
 * Description: A simple shell program to execute commands
 * Return: 0 (success)
 */

int main(void)
{
	char *cmd, **argv, *arg_str, *cm_str;
	int pid, status, ret, c_count = 0;

	cmd = get_cmd();
	cm_str = get_cmd_file(cmd);
	arg_str = get_args_str(cmd);
	argv = get_args(arg_str);

	while (strcmp(cmd, "exit") != 0)
	{
		c_count++;
		pid = fork();
		if (pid == 0)
			execve(cm_str, argv, NULL);
		ret = waitpid(pid, &status, 0);
		if (ret != pid)
		{
			if (argv[0] != NULL)
				printf("hsh: %d: %s: not found\n",
				       c_count, argv[0]);
			return (-1);
		}
		free(arg_str);
		free(argv);

		cmd = get_cmd();
		cm_str = get_cmd_file(cmd);
		arg_str = get_args_str(cmd);
		argv = get_args(arg_str);
	}
	free(cm_str);
	free(arg_str);
	free(argv);

	return (0);
}

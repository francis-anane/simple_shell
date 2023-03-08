#include "main.h"
/**
 * get_cmd - Gets a string entered fron standard input.
 * @rd: An int pointer to check for EOF
 * Return: A pointer to the string read at stdin.
 */
char *get_cmd(int *rd)
{
	char *buff, *in_cmd, *prmt = "($)";
	size_t n;

	printf("%s", prmt);
	*rd = getline(&buff, &n, stdin);
	in_cmd = strsep(&buff, "\n");
	return (in_cmd);

}

/**
 * get_cmd_file - Get the string to be passed as the file for exec system call.
 * @cmd_str: The string to get command file from.
 * Return: A pointer to the command file string.
 */

char *get_cmd_file(char *cmd_str)
{
	char *cmd_file;

	cmd_file = strtok(cmd_str, " ");
	return (cmd_file);
}

/**
 * cmdl_arg - Check command line arguments
 * @ac: argument count
 * @av: argument vector
 * @c: command count
 */

void cmdl_arg(int ac, int c, char **av)
{
	if (ac > 1)
	{
		if (access(av[1], F_OK) != 0)
			printf("%s: %d: can't open %s\n", av[0], c, av[1]);
		exit(0);
	}
}

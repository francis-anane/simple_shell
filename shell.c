#include "main.h"
/**
 * get_cmd - Gets a string entered fron standard input.
 *
 *
 * Return: A pointer to the string entered.
 */
char *get_cmd()
{
	char *buff, *cmd, *prmt = "($)";
	size_t n;
	int rd;

	if (isatty(STDIN_FILENO) == 1)
		printf("%s", prmt);
	rd = getline(&buff, &n, stdin);
	/* Handle Ctrl-D*/
	if (rd == EOF)
	{
		printf("\n");
		exit(0);
	}
	cmd = strsep(&buff, "\n");

	return (cmd);

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

#include "main.h"

/**
 * get_cmd - Gets a string entered fron standard input.
 * @rd: An int pointer to check for EOF
 * Return: A pointer to the string read at stdin.
 */
char *get_cmd(int *rd)
{
	char *in_cmd, *prmt = "($) ";
	char *buff[] = {NULL};
	size_t n;

	if (isatty(STDIN_FILENO) == 1)
		write(STDERR_FILENO, prmt, 4);
	*rd = getline(buff, &n, stdin);
	in_cmd = strtok(*buff, "\n");
	/*free(*buff);*/
	return (in_cmd);

}

/**
 * cmdl_arg - Check command line arguments
 * @ac: argument count
 * @av: argument vector
 * @c: command count
 */

void cmdl_arg(int ac, char **av, int c)
{
	if (ac > 1)
	{
		if (access(av[1], F_OK) == 0)
		{
			_print_err(2, av[0], ": ");
			print_number_err(c);
			_print_err(3, ": can't open ", av[1], "\n");
		}
		exit(0);
	}
}

/**
 * _cmdfile - Extract first non empty token from a parsed string.
 * @cmd_str: The string to get token from.
 * Return: A pointer to the token string.
 */

char *_cmdfile(char *cmd_str)
{
	char *cmd_file;

	cmd_file = strtok(cmd_str, " ");
	return (cmd_file);
}

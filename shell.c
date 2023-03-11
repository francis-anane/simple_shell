#include "main.h"
/**
 * get_cmd - Gets a string entered fron standard input.
 * @rd: An int pointer to check for EOF
 * Return: A pointer to the string read at stdin.
 */
char *get_cmd(int *rd)
{
	char *in_cmd, *prmt = " ($)";
	char *buff[] = {NULL};
	size_t n;

	printf("%s", prmt);
	*rd = getline(buff, &n, stdin);
	in_cmd = strsep(buff, "\n");
	return (in_cmd);

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

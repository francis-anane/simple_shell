#include "main.h"

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

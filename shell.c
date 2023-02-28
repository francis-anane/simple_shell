#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"
/**
 * get_cmd - Gets a string entered fron standard input.
 *
 *
 * Return: A pointer to the string entered.
 */
char *get_cmd()
{
	char *prompt = "($)";
	char *cmd;
	char *buff;
	size_t n;

	write(STDOUT_FILENO, prompt, sizeof(prompt));
	getline(&buff, &n, stdin);
	cmd = strsep(&buff, "\n");
	return (cmd);

}

/**
 * get_args_str - Get argument string by removing back slashes.
 *
 * @c_str: The argument string.
 * Return: A pointer to the arguments string.
 */
char *get_args_str(char *c_str)
{
	char *c_args;
	char *tok_str;
	unsigned int i, j;
	int size = 0;

	c_args = rindex(c_str, '/');
	if (c_args == NULL)
		c_args = c_str;

	for (i = 0; i < strlen(c_args); i++)
	{
		if (c_args[i] == '/')
			continue;
		size++;
	}

	tok_str = malloc(size * sizeof(char));
	if (tok_str == NULL)
		return (NULL);
	j = 0;
	for (i = 0; i < strlen(c_args); i++)
	{
		if (c_args[i] == '/')
			continue;
		tok_str[j] = c_args[i];
		j++;
	}
	tok_str[j] = '\0';

	return (tok_str);
}

/**
 * get_args - Proccess a string to be used as arguments for exec system call.
 * @args_str: The string to process.
 * Return: A pointer to an array of strings.
 */

char **get_args(char *args_str)
{
	int size = 1;
	unsigned int i = 0, j;
	char *tok;
	char **args;

	for (; i < strlen(args_str); i++)
		if (args_str[i] == ' ')
			size++;

	/*get tokens for command arguments*/

	args = malloc((size + 1) * sizeof(char *));
	if (args == NULL)
		return (NULL);
	i = 0;
	tok = strtok(args_str, " ");
	while (tok != NULL)
	{
		j = 0;
		args[i] = malloc((strlen(tok) + 1) * sizeof(char));
		if (args[i] == NULL)
			return (NULL);
		for (; j < strlen(tok); j++)
			args[i][j] = tok[j];
		args[i][j] = '\0';

		tok = strtok(NULL, " ");
		i++;
	}
	args[i + 1] = NULL;

	return (args);

}

/**
 * get_cmd_file - Get the string to be passed as the file for exec system call.
 * @cmd_str: The string to get command file from.
 * Return: A pointer to the command file string.
 */

char *get_cmd_file(char *cmd_str)
{
	char *cmd_file;
	unsigned int i = 0;

	cmd_file = malloc(sizeof(char *));
	if (cmd_file == NULL)
		return (NULL);
	for (; i < strlen(cmd_str); i++)
	{
		if (cmd_str[i] == ' ')
			break;
		cmd_file[i] = cmd_str[i];
	}
	cmd_file[i] = '\0';
	return (cmd_file);
}

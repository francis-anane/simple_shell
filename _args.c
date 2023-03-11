#include "main.h"

/**
 * get_args - Proccess a string to be used as arguments for exec system call.
 * @args_str: The string to process.
 * Return: A pointer to an array of strings.
 */

char **get_args(char *args_str)
{
	int size = 0;
	unsigned int i = 0;
	char *tok, **args, *arg0;

	for (; i < strlen(args_str); i++)
	{
		if (args_str[i] == ' ')
			size++;
	}
	args = malloc((size + 2) * sizeof(char *));
	if (args == NULL)
		return (NULL);
	tok = strtok(args_str, " ");
	if (tok == NULL)
		return (args);/*to free*/
	arg0 = _arg0(tok);
	i = 0;
	args[i] = malloc(strlen(arg0) + 1);
	if (args[i] == NULL)
		return (args);/*to free*/
	strcpy(args[i], arg0);
	strcat(args[i], "\0");
	tok = strtok(NULL, " ");
	while (tok != NULL)
	{
		i++;
		args[i] = malloc(strlen(tok) + 1);
		if (args[i] == NULL)
			return (args);
		strcpy(args[i], tok);
		strcat(args[i], "\0");
		tok = strtok(NULL, " ");
	}
	args[i + 1] = NULL; /*Add null for execve arg*/
	return (args);
}

/**
 * _arg0 - Get command file as first argument from command string.
 * @c_file: Command string first token
 * Return: Command file string
 */

char *_arg0(char *c_file)
{
	char *arg0, *arg0_tok;

	arg0 = rindex(c_file, '/');
	if (arg0 == NULL)
		return (c_file);
	arg0_tok = strtok(arg0, "/");
	return (arg0_tok);
}

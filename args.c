#include "main.h"

/**
 * get_args - Proccess a string to be used as arguments for exec system call.
 * @args_str: The string to process.
 * @arg0: First argumemt to the exec system call
 * Return: A pointer to an array of strings.
 */

char **get_args(char *args_str, char *arg0)
{
	int size;
	unsigned int i = 0;
	char *tok, **args;

	size = token_count(args_str, ' ');
	args = malloc((size + 1) * sizeof(char *));
	if (args == NULL)
		return (NULL);
	tok = strtok(args_str, " ");
	if (tok == NULL)
		return (args);/*to free*/
	i = 0;
	args[i] = malloc(string_len(arg0) + 1);
	if (args[i] == NULL)
		return (args);/*to free*/
	_strcpy(args[i], arg0);
	_strcat(args[i], "\0");
	tok = strtok(NULL, " ");
	while (tok != NULL)
	{
		i++;
		args[i] = malloc(string_len(tok) + 1);
		if (args[i] == NULL)
			return (args);
		_strcpy(args[i], tok);
		_strcat(args[i], "\0");
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
	char *arg0, *c_cp;

	c_cp = string_dup(c_file);
	arg0 = after_lindex(c_cp, '/');
	if (arg0 == NULL)
	{
		free(c_cp);
		return (c_file);
	}
	free(c_cp);
	return (arg0);
}

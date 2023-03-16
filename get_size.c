#include "main.h"

/**
 * array_size - Checks for the size of an array of strings.
 * @arr:  The array to get size of.
 *
 * Return: The size of the array, 0 if array is null.
 */

int array_size(char **arr)
{
	int size = 0;

	if (arr == NULL)
		return (0);
	while (*arr)
	{
		size++;
		arr++;
	}
	arr -= size;
	return (size);
}

/**
 * token_count - check the number of tokens in a string by a given delimeter
 * @str: The string to get tokens from.
 * @delim: tokens delimeter
 * Return: The number of tokens, 0 if str is null.
 */

int token_count(char *str, const char delim)
{
	int tokens = 0;

	if (str == NULL)
		return (0);
	if (delim == ' ')
		tokens++;
	while (*str)
	{
		if (*str == delim)
			tokens++;
		str++;
	}
	if (delim == ' ')
		str -= (tokens - 1);
	else
		str -= tokens;
	return (tokens);
}

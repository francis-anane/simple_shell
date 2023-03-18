#include "main.h"

/**
 * from_lindex - Point from the last index of a
 * specified delimeter in a string.
 * @str:  The string.
 * @delim: The delimeter character
 *
 * Return: The string from the pointed index or null if str is null
 * or delimeter was not found  in str.
 */

char *from_lindex(char *str, char delim)
{
	int indx = 0, i, check, len;

	check = string_len(str);
	len = string_len(str);

	for (i = 0; i < len; i++)
	{
		if (str[i] == delim)
		{
			indx = i;
			check--;
		}
	}
	if (check == len)
		return ("\0");

	return (str + indx);
}

/**
 * after_lindex - Point after the last index of a specified delimeter
 * in a string
 * @str:  The string.
 * @delim: The delimeter character
 *
 * Return: The string after the pointed index or null if str is null
 * or delimeter was not found  in str.
 */

char *after_lindex(char *str, char delim)
{
	int indx = 0, i, check, len;

	check = string_len(str);
	len = string_len(str);

	for (i = 0; i < len; i++)
	{
		if (str[i] == delim)
		{
			indx = i;
			check--;
		}
	}
	if (check == len)
		return ("\0");
	return (str + (indx + 1));
}

/**
 * from_findex - Point from the first index of a
 * specified delimeter in a string
 * @str:  The string.
 * @delim: The delimeter character
 * Return: The string from the first index or null if str is null
 * or delimeter was not found  in str.
 */

char *from_findex(char *str, char delim)
{
	int indx, check, len;

	check = string_len(str);
	len = string_len(str);

	for (indx = 0; indx < len; indx++)
	{
		if (str[indx] == delim)
		{
			check--;
			break;
		}
	}
	if (check == len)
		return ("\0");

	return (str + indx);
}

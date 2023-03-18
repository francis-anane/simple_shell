#include "main.h"

/**
 * string_dup - Duplicate a string.
 * @str: The string to duplicate
 *
 * Return: A pointer to the duplicate, or null if str is null.
 */

char *string_dup(char *str)
{
	int size, i = 0;
	char *dup;

	size = string_len(str);
	if (size == 0)
		return (NULL);
	size += 1;/*for \0*/

	dup = malloc(size);
	if (dup == NULL)
		return (NULL);

	for (; i < (size - 1); i++)
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}

/**
 * string_len - Checks for the length of a string.
 * @str:  The string to check.
 *
 * Return: The length of the string, 0 if str is null.
 */

int string_len(char *str)
{
	int len = 0;

	if (str == NULL)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

/**
 * *_strcat - concatenates two strings.
 * @dest : first string.
 * @src : second string.
 * Return: a pointer to the resulting string dest
 */

char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - Compares pointers to two strings.
 * @s1: A pointer to the first string to be compared.
 * @s2: A pointer to the second string to be compared.
 *
 * Return: If str1 < str2, the negative difference of the first
 * unmatched characters.
 * If str1 == str2, 0.
 * If str1 > str2, the positive difference of the first
 * unmatched characters.
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
 * _strcpy - Copies a string pointed to by @src, including the
 *           terminating null byte, to a buffer pointed to by @dest.
 * @dest: A buffer to copy the string to.
 * @src: The source string to copy.
 *
 * Return: A pointer to the destination string @dest.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

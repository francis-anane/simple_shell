#include "main.h"
/**
 * free_arr - Deallocate a malloc allocated array of strings.
 * @arr: The array to deallocate.
 * Return: 0 on success, -1 on failure.
 */

int free_arr(char **arr)
{
	int size = 0, i = 0;

	while (*arr)
	{
		size++;
		arr++;
	}
	arr -= size;
	for (; i < size; i++)
		free(arr[i]);
	free(arr);
	if (arr != NULL)
		return (-1);
	return (0);
}

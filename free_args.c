#include "main.h"
/**
 * free_arr - Deallocate a malloc allocated array of strings.
 * @arr: The array to deallocate.
 */

void free_arr(char **arr)
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
}

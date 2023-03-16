#include "main.h"

/**
 * free_mem - Free all malloc char* allocations passed as argument.
 *
 * @n: The last argument of the list of arguments
 *
 */

void free_mem(const unsigned int n, ...)
{
	unsigned int i;

	va_list ap;

	if (n == 0)
		return;

	va_start(ap, n);

	for (i = 0; i < n; i++)
		free(va_arg(ap, char*));

	va_end(ap);
}

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

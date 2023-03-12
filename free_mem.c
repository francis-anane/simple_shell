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

#include "main.h"

int _putchar(char c);

/**
 * _putchar - print a character to stdout
 * @c: the character.
 * Return: The size of the character written.
 */

int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
 * print_number - Prints an integer to stdout.
 * @n: The integer to be printed.
 */
void print_number(int n)
{
	unsigned int m;

	m = n;
	if (n < 0)
	{
		_putchar('-');
		m = -m;

	}

	if ((m / 10) > 0)
		print_number(m / 10);

	_putchar(m % 10 + '0');
}

/**
 * _print - print out list of argumnts to stdout
 *
 * @n: The last argument of the list of arguments
*/

void _print(const unsigned int n, ...)
{
	unsigned int i;
	va_list ap;
	char *str;

	if (n == 0)
		return;
	va_start(ap, n);
	for (i = 0; i < n; i++)
	{
		str = va_arg(ap, char*);
		write(STDOUT_FILENO, str, string_len(str));
	}
	va_end(ap);
}

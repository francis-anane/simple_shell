#include "main.h"

void _putchar_err(char c);

/**
 * _print_err - print out list of arguments to stderr.
 *
 * @n: The last argument of the list of arguments
 *
 */

void _print_err(const unsigned int n, ...)
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
		write(STDERR_FILENO, str, string_len(str));
	}

	va_end(ap);
}

/**
 * _putchar_err - print a character to stderr
 * @c: the character.
 */

void _putchar_err(char c)
{
	write(2, &c, 1);
}

/**
 * print_number_err - Prints an integer to stderr.
 * @n: The integer to be printed.
 */
void print_number_err(int n)
{
	unsigned int m;

	m = n;
	if (n < 0)
	{
		_putchar_err('-');
		m = -m;

	}

	if ((m / 10) > 0)
		print_number_err(m / 10);

	_putchar_err(m % 10 + '0');
}

/**
 * _putchar - write a character to stdout
 * @c: The character to write
 */

void _putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
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

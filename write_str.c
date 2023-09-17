#include "main.h"

/**
 * print_string - Prints a string
 * @ap: A variable argument list containing a string to be printed
 * @count: count number of characters
 *
 * * Return: Nothing
 */

void print_string(va_list ap, int *count)
{
	char *str;

	str = va_arg(ap, char *);
	if (!str)
		_putchar('\0');
	while (*str)
	{
		*count += _putchar(*str);
		str++;
	}
}


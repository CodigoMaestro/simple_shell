#include "main.h"

/**
 * print_char - Prints a character
 * @ap: A variable argument list containing a character to be printed
 * @count: count number of characters
 *
 * Return: Nothing
 */

void print_char(va_list ap, int *count)
{
	int c;

	c = va_arg(ap, int);
	*count += _putchar(c);
}

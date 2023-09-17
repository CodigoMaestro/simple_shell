#include "main.h"

/**
 * print_space - Prints empty
 * @ap: A variable argument list containing a string to be printed
 * @count: count number of characters
 *
 * * Return: Nothing
 */

void print_space(va_list ap, int *count)
{
	(void) ap;
	*count += _putchar(' ');
}

/**
 * print_percent - Prints a percent sign
 * @ap: A variable argument list containing nothing
 * @count: count number of characters
 *
 * Return: Nothing
 */
void print_percent(va_list ap, int *count)
{
	(void) ap;
	*count += _putchar('%');
}


/**
 * print_unsigned - Prints unsigned int
 * @ap: A variable argument list containing nothing
 * @count: count number of characters
 *
 * Return: Nothing
 */

void print_unsigned(va_list ap, int *count)
{
	char *temp_ptr, *buffer;
	int num, length;

	num = va_arg(ap, int);
	buffer = (char *)malloc(12);
	if (buffer == NULL)
		return;
	length = int_to_string(num, buffer, 12);
	if (length < 0)
		return;
	temp_ptr = buffer
		;
	while (*temp_ptr)
	{
		*count += _putchar(*temp_ptr);
		temp_ptr++;
	}
	free(buffer);
}



/**
 * print_hex - Prints an integer in hexadecimal format
 *
 * @ap: A va_list containing the integer to print
 * @count: A pointer to a counter of printed characters
 */
void print_hex(va_list ap, int *count)
{
	unsigned int num;
	char hex[100];
	int i, length;

	num = va_arg(ap, unsigned int);
	if (num == 0)
	{
		*count += _putchar('0');
		return;
	}
	for (i = 0; num != 0; i++)
	{
		hex[i] = "0123456789abcdef"[num % 16];
		num /= 16;
	}
	length = i;
	for (i = length - 1; i >= 0; i--)
		*count += _putchar(hex[i]);
}

/**
 * print_HEX - Prints an integer in hexadecimal format
 *
 * @ap: A va_list containing the integer to print
 * @count: A pointer to a counter of printed characters
 */
void print_HEX(va_list ap, int *count)
{
	unsigned int num;
	char hex[100];
	int i, length;

	num = va_arg(ap, unsigned int);
	if (num == 0)
	{
		*count += _putchar('0');
		return;
	}
	for (i = 0; num != 0; i++)
	{
		hex[i] = "0123456789ABCDEF"[num % 16];
		num /= 16;
	}
	length = i;
	for (i = length - 1; i >= 0; i--)
		*count += _putchar(hex[i]);
}

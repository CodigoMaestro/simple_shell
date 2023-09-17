#include "main.h"

/**
 * print_integer - Prints an integer
 * @ap: A variable argument list containing an integer to be printed
 * @count: count number of characters
 *
 * Return: Nothing
 */
void print_integer(va_list ap, int *count)
{
	char *temp_ptr, *buffer;
	int num, length;

	num = va_arg(ap, int);
	buffer = malloc(sizeof(buffer));
	if (buffer == NULL)
		return;

	length = int_to_string(num, buffer, sizeof(buffer));
	if (length < 0)
		return;

	temp_ptr = buffer;

	while (*temp_ptr)
	{
		*count += _putchar(*temp_ptr);
		temp_ptr++;
	}
	free(buffer);
}

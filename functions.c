#include "main.h"

/**
 * int_to_string - a function to convert integers to string
 * @num: the num of strings
 * @buffer: the loction of string
 * @bufferSize: the size of location
 *
 * Return: length of string
 **/

int int_to_string(int num, char *buffer, int bufferSize)
{
	int i, j, length, isNegative;

	if (num == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		return (1);
	}
	isNegative = 0;
	if (num < 0)
	{
		isNegative = 1;
		num = -num;
	}
	length = 0;
	while (num > 0)
	{
		buffer[length++] = (num % 10) + '0';
		num /= 10;
	}
	if (isNegative)
		buffer[length++] = '-';
	if (length >= bufferSize)
		return (-1);
	buffer[length] = '\0';
	for (i = 0, j = length - 1; i < j; i++, j--)
	{
		char temp;

		temp = buffer[i];

		buffer[i] = buffer[j];
		buffer[j] = temp;
	}
	return (length);
}
/**
 * decimal_to_binary - convert unsigned int to binary
 *
 * @num: unsigned integer
 * @count: pointer to int
 * Return: 0 (Success)
 */
int decimal_to_binary(unsigned int num, int *count)
{
	if (num > 1)
	{
		if (num % 2 == 0)
		{
			*count += 1;
			decimal_to_binary(num / 2, count);
			_putchar('0');
		}
		else
		{
			*count += 1;
			decimal_to_binary(num / 2, count);
			_putchar('1');
		}
	}
	else
	{
		_putchar('1');
		*count += 1;
	}
	return (0);
}

/**
 * decimal_to_HEX - convert unsigned integer to hexadecimal
 *
 * @num: Unsigned integer
 * @count: Integer pointer that increments when print is successful
 * Return: 0 (Success), -1 (Error)
 */
int decimal_to_HEX(unsigned int num, int *count)
{
	char hex[100];
	int i, length;

	if (num == 0)
	{
		*count += _putchar('0');
		return (0);
	}
	for (i = 0; num != 0; i++)
	{
		hex[i] = "0123456789ABCDEF"[num % 16];
		num /= 16;
	}
	length = i;
	for (i = length - 1; i >= 0; i--)
		*count += _putchar(hex[i]);
	return (0);
}

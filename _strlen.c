#include "shell.h"

/**
 * _strlen - a funcion to calculate length of string
 * @str: string
 *
 * Return: length of string
 **/

int _strlen(const char *str)
{
	int len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

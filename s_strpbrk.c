#include "shell.h"

/**
 * _strpbrk - searches a string for any of a set of bytes.
 * @str: main string.
 * @find: string(s) to find.
 * Return: a pointer to the byte in s that matches one of the
 * bytes in accept, or NULL if no such byte is found.
 */

char *_strpbrk(char *str, char *find)
{
	unsigned int i, j;

	for (i = 0; *(str + i) != '\0'; i++)
	{
		for (j = 0; *(find + j) != '\0'; j++)
		{
			if (*(str + i) == *(find + j))
				return (str + i);
		}
	}
	return ('\0');
}

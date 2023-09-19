#include "main.h"

/**
 * *_strtok- a funtion to tokenize strings
 * @ str:  string to search for tokenization
 * @delim: delimiter string/character
 *
 * Return: pointer to tokenized string
 **/

char *_strtok(char *str, char *delim)
{
	char *token;
	static char *last_token;

	token = NULL;
	last_token = NULL;

	if (str == NULL)
		last_token = str;
	else
	{
		if (last_token == NULL)
			return (NULL);

		str = last_token;
	}

	token = _strpbrk(str, delim);

	if (token != NULL)
	{
		*token = '\0';
		last_token = token + 1;
	}
	else
		last_token = NULL;

	return (str);
}

#include "main.h"

/**
 * shell_env - print the environment
 * @env: a pointer to character pointer
 *
 * Return: Nothing
 **/

int shell_env(char **env)
{
	unsigned int i;

	i = 0;
	while (env[i] != NULL)
	{
		_printf("%s\n", env[i]);
		i++;
	}
	return (0);
}

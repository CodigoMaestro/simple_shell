#include "main.h"

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

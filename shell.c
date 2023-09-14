#include "shell.h"


/**
 * main - entry point
 * ac: int
 * av: char
 * env: char data type
 * Return: 0
 */

int main(int ac, char **av, char **env)
{
	char *buffer = NULL;
	size_t buff_size = 0;
	ssize_t characters_read;
	int i, j;
	char *buffer_copy = NULL;
	char *token;
	const char *delim = " ";
	int token_count;
	char **cmd = NULL;

	(void)ac;
	(void)env;

	while (1)
	{
		printf("($) ");
		characters_read = getline(&buffer, &buff_size, stdin);
		
		if (characters_read == -1)
		{
			printf("No characters read, Exiting shell .....\n");
			break;
		}

		token_count = 0;

		if (characters_read > 0 && buffer[characters_read - 1] == '\n')
		{
			buffer[characters_read - 1] = '\0';
		}


		buffer_copy = strdup(buffer);

		if (buffer_copy == NULL)
		{
			printf("%s: Could not allocate memory to buffer_copy", av[0]);
			continue;
		}


		token = strtok(buffer, delim);

		while (token != NULL)
		{
			token_count++;
			token = strtok(NULL, delim);
		}


		cmd = malloc(sizeof(char *) * (token_count + 1));
		
		if (cmd == NULL)
		{
			perror("Could not allocate memory");
			/*free(buffer);*/
			free(buffer_copy);
			return (-1);
		}

		token = strtok(buffer_copy, delim);

		for (i = 0; token != NULL; i++)
		{
			cmd[i] = strdup(token);

			if (cmd[i] == NULL)
			{
				perror("Could not allocate memory to tokens");
				/*free(buffer);*/
				free(buffer_copy);

				for (j = 0; j < i; j++)
				{
					free(cmd[j]);
				}

				free(cmd);
				continue;
			}

			/*strcpy(av[i], token);*/
			token = strtok(NULL, delim);
		}
		cmd[token_count] = NULL;

		execve_commands(cmd);
			
		for (i = 0; cmd[i] != NULL; i++)
		{
			free(cmd[i]);
		}
		free(cmd);
		/*free(buffer_copy);*/
	}
	/*free(buffer);*/
	return (0);
}

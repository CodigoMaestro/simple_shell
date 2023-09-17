#include "main.h"

/**
 * main - prints to stdout
 * @argv: argument vector
 * @argc: argument count
 * @env: environmental variable
 *
 * Return: Always 0.
 */

int main(int argc, char **argv, char **env)
{
	char *line = NULL;
	size_t n = 0;
	ssize_t read;

	if (argc > 1)
	{
		execute_command(argv[1], &argv[1], env);
		return (0);
	}

	while (1)
	{
		char *arguments[1024];
		char *command;
		int i;

		_printf("($) ");
		read = getline(&line, &n, stdin);
		if (read == -1)
		{
			perror("getline error");
			return (-1);
		}
		
		if (line[0] == '#')
		{
			line = NULL;
			n = 0;
			continue;
		}

		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		command = strtok(line, " ");
		arguments[0] = command;

		i = 1;
		
		while ((arguments[i] = strtok(NULL, " ")) != NULL)
			i++;

		if (_strcmp(command, "exit") == 0)
		{
			free(line);
			exit(0);
		}
		if (_strcmp(command, "env") == 0)
		{
			shell_env(env);
			continue;
		}
		execute_command(command, arguments, env);

		free(line);
		line = NULL;
		n = 0;
	}
}

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
	(void)argc;
	(void)env;
	(void)argv;

	while (1)
	{
		char *arguments[1024];
		char *command;

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

		/* Remove the newline character from the input*/
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';
		/* Split the input into command and arguments */
		command = line;
		arguments[0] = command;
		arguments[1] = NULL;
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
	}
}

#include "main.h"

/**
 * execute_shell - main loop of the shell
 * @env: environmental variable
 *
 * Return: Always 0.
 */

int execute_shell(char **env)
{
	char *line = NULL;
	size_t n = 0;
	ssize_t read;

	while (1)
	{
		char *arguments[1024], *command;
		int i, last_exit_status;

		last_exit_status  = 0;

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
			if (arguments[1] != NULL)
				exit(_atoi(arguments[1]));
			else
				exit(0);
		}
		if (_strcmp(command, "env") == 0)
		{
			shell_env(env);
			continue;
		}
		if (_strcmp(command, "echo") == 0 && _strcmp(arguments[1], "$$") == 0)
		{
			_printf("%d\n", getppid());
			continue;
		}
		if (_strcmp(command, "echo") == 0 && _strcmp(arguments[1], "$?") == 0)
		{
			_printf("%d\n", last_exit_status);
			continue;
		}
		if (_strcmp(command, "cd") == 0)
		{
			if (arguments[1] == NULL)
			{
				char *home_dir;

				home_dir = getenv("HOME");
				chdir(home_dir);
			}
			else
				chdir(arguments[1]);

			continue;
		}
		last_exit_status = execute_command(command, arguments, env);

		free(line);
		line = NULL;
		n = 0;
	}
}

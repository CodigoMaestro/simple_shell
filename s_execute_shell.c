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
	char **arguments;

	while (1)
	{
		_printf("($) ");

		read = getline(&line, &n, stdin);
		if (read == -1)
		{
			perror("getline error");
			return (-1);
		}
		if (line[0] == '#')
		{
			free(line);
			line = NULL;
			n = 0;
			continue;
		}
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';
		arguments = tokenize_line(line);
		if (arguments == NULL)
		{
			free(line);
			line = NULL;
			n = 0;
			continue;
		}
		execute_command(arguments[0], arguments, env);
		free(arguments);
		free(line);
		line = NULL;
		n = 0;
	}

	return (0);
}


/**
 * shell_exit - exit the shell
 * @arguments: the exit status to use, or NULL to use the default status
 *
 * Return: the exit status to use
 */
int shell_exit(char **arguments)
{
	if (arguments[1] != NULL)
		exit(_atoi(arguments[1]));

	exit(0);
}

/**
 * shell_echo_ppid - print the parent process ID
 *
 * Return: Always 0.
 */
int shell_echo_ppid(void)
{
	_printf("%d\n", getppid());

	return (0);
}


/**
 * shell_cd - change the current working directory
 * @arguments: the directory to change to,
 * or NULL to change to the home directory
 *
 * Return: Always 0.
 */
int shell_cd(char **arguments)
{
	if (arguments[1] == NULL)
	{
		char *home = getenv("HOME");

		chdir(home);
	}
	else
		chdir(arguments[1]);

	return (0);
}

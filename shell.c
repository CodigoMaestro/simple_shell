#include "shell.h"

/**
 * main - prints to stdout
 * @argv: argument vector
 * @argc: argument count
 * @env: environmental variable
 *
 * Return: Always 0.
 */

int main(int argc, char *argv[], char *env[])
{
	char *cmd_line;
	ssize_t read_line;
	size_t var;
	(void) argc;
	(void) argv;
	(void) env;

	cmd_line = NULL;
	var = 0;

	while (TRUE)
	{
		prompt_user();
		read_line = getline(&cmd_line, &var, stdin);

		if (read_line == -1)
		{
			perror("getline");
			break;
		}

		write(STDOUT_FILENO, cmd_line, (size_t)read_line);
		free(cmd_line);
		cmd_line = NULL;
		var = 0;
	}

	return (0);
}

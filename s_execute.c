#include "main.h"

/**
 * execute_command - a function that accepts arguments and execute as commands
 * @command: commands to be executed
 * @arguments: argument input
 * @env: environmental variables
 *
 * Return: Nothing
 **/

void execute_command(char *command, char **arguments, char **env)
{
	pid_t pid;
	int status;
	char *path;
	char *path_copy;
	char *path_token;
	char *command_path;

	command_path = NULL;

	if (command[0] == '/')
	{
		if (access(command, F_OK) == 0)
			command_path = strdup(command);
	}
	else
	{
		path = getenv("PATH");
		path_copy = strdup(path);
		path_token = strtok(path_copy, ":");

		while (path_token != NULL)
		{
			command_path = strdup(path_token);
			command_path = _strcat(command_path, "/");
			command_path = _strcat(command_path, command);
			if (access(command_path, F_OK) == 0)
			break;
		free(command_path);
		command_path = NULL;
		path_token = strtok(NULL, ":");
		}

		free(path_copy);
	}

	if (command_path == NULL)
	{
		_printf("%s: command not found\n", command);
		return;
	}

	pid = fork();
	/* Execute the command using execve */
	if (pid == 0)
	{
		execve(command_path, arguments, env);
		perror(command_path);
		exit(1);
	}
	/*Parent process*/
	else if (pid > 0)

		waitpid(pid, &status, 0);
	else
	{
		perror("forking error");
		exit(1);
	}

	free(command_path);
}

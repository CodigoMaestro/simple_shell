#include "main.h"

/**
 * search_command_path - search for the path of the command
 * @command: command to search
 *
 * Return: the path of the command, or NULL if not found
 */
char *search_command_path(char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *path_token = strtok(path_copy, ":");
	char *command_path = NULL;

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
	return (command_path);
}

/**
 * execute_child_process - execute the command in the child process
 * @command_path: path of the command
 * @arguments: argument input
 * @env: environmental variables
 *
 * Return: Nothing
 */
void execute_child_process(char *command_path, char **arguments, char **env)
{
	execve(command_path, arguments, env);
	perror(command_path);
	exit(1);
}

/**
 * execute_parent_process - wait for the child process to finish
 * @pid: process id of the child process
 *
 * Return: Nothing
 */
void execute_parent_process(pid_t pid)
{
	int status;

	waitpid(pid, &status, 0);
}

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
	char *command_path;

	if (command[0] == '/')
	{
		if (access(command, F_OK) == 0)
			command_path = strdup(command);
	}
	else
		command_path = search_command_path(command);

	if (command_path == NULL)
	{
		_printf("%s: command not found\n", command);
		return;
	}

	pid = fork();
	if (pid == 0)
		execute_child_process(command_path, arguments, env);
	else if (pid > 0)
		execute_parent_process(pid);
	else
	{
		perror("forking error");
		exit(1);
	}

	free(command_path);
}

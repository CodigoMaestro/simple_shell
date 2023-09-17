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

	pid = fork();
	/* Execute the command using execve */
	if (pid == 0)
	{
		execve(command, arguments, env);
		perror(command);
		exit(1);
	}
	/*Parent process*/
	else if (pid > 0)
	{
		int status;

		waitpid(pid, &status, 0);
	}
	else
	{
		perror("forking error");
		exit(1);
	}
}

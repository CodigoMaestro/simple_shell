#include "main.h"

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
		/* Remove the newline character from the input*/
		if (line[read - 1] == '\n')
			line[read -1 ] = '\0';
		/* Split the input into command and arguments */
		command = line;
		arguments[0] = command;
		arguments[1] = NULL;
		
		if (strcmp(command, "exit") == 0)
		{
			free(line);
			exit(0);
		}
		execute_command(command, arguments, env);
	}
}

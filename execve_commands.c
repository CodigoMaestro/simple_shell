#include "shell.h"
#include <errno.h>

void execve_commands(char **cmd)
{
	/*char **commands = NULL;*/
	/*char *strtoked_command = NULL;*/
	char *command_to_execute = command_paths(cmd[0]);

	if (command_to_execute)
	{
		pid_t child_pid = fork();

		if (child_pid == -1)
		{
			perror("Fork failed");
		}
		else if (child_pid == 0)
		{
			if (execve(command_to_execute, cmd, NULL) == -1)
			{
				perror("Execve failed");
				exit(EXIT_FAILURE);
			}
		}
		else {
			int status;
			waitpid(child_pid, &status, 0);
		}
		free(command_to_execute);
	}
	else {
		printf("Command not found: %s\n", cmd[0]);
	}

	/*if (cmd && cmd[0])
	{*/
		/*commands = cmd[0];*/

		/*printf("%s", commands);*/

		/*strtoked_command = command_paths(commands);*/

		/*command_to_execute = command_paths(cmd[0]);*/

		/*if (execve(strtoked_command, cmd, NULL) == -1)
		{
			perror("Error");
		};*/

		/*if (command_to_execute)
		{
			if (execve(command_to_execute, cmd, NULL) == -1)
			{
				perror("Error");
			}
		}
		else{
			perror("Command not found");
		}
	}*/
}

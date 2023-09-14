#include "shell.h"

/**
 * command_paths - entry point
 * @cmd: char
 * Return: 0
 */

char *command_paths(char *cmd)
{
	char *path;
	char *path_dup;
	char *path_token;
	char *file_path;
	int cmd_length, dir_length;
	struct stat buffer;

	path = getenv("PATH");

	if (path)
	{
		path_dup = strdup(path);
		cmd_length = strlen(cmd);

		path_token = strtok(path_dup, ":");

		while (path_token != NULL)
		{
			dir_length = strlen(path_token);

			file_path = malloc(cmd_length + dir_length + 2);

			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, cmd);
			strcat(file_path, "\0");

			if (stat(file_path, &buffer) == 0)
			{
				free(path_dup);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}

		free(path_dup);

		if (stat(cmd, &buffer) == 0)
		{
			return (cmd);
		}
		return (NULL);
	}
	return (NULL);
}

#include "shell.h"

/**
 * prompt_user - function to display commandline prompt indicator
 *
 * Return: Nothing
 **/

void prompt_user(void)
{
	const char *prompt = "($) ";
	ssize_t byte_written;
      	int prompt_len = _strlen(prompt);

	if (isatty(STDIN_FILENO))
		byte_written = write(STDIN_FILENO, prompt, prompt_len);
	if (byte_written != prompt_len)
	{
		perror("prompt error");
		exit(EXIT_FAILURE);
	}
}

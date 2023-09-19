#include "main.h"

/**
 * main - prints to stdout
 * @argv: argument vector
 * @argc: argument count
 * @env: environmental variable
 *
 * Return: Always 0.
 */

int main(int argc, char **argv, char **env)
{
	if (argc > 1)
	{
		execute_command(argv[1], &argv[1], env);
		return (0);
	}

	return (execute_shell(env));
}

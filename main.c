#include "main.h"

/**
 * main - prints to stdout
 * @argv: argument vector
 * @argc: argument count
 * @env: environmental variable
 *
 * Return: Always 0.
 */

int main(int argc __attribute__((unused)), char **argv, char **env)
{
	if (argv[1] != NULL )
	{
		execute_command(argv[1], &argv[1], env);
		return (0);
	}

	return (execute_shell(env));
}

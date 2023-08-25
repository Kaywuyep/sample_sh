#include "shell.h"
/**
 * exec_cmd - a function that executes the command
 * @argv: arguments
 */
void execute_command(char **argv)
{
	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}

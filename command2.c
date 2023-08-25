#include "shell.h"
/**
 * exec_cmd - a function that executes the command
 * @command: arguments
 */
void execute_command(char *command)
{
	char *args[2];

	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		free(command);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/*Child process*/

		/*Tokenize the command line*/
		args[0] = command;
		args[1] = NULL;

		/*Use execve to execute the command*/
		if (execve(command, args, NULL) == -1)
		{
			perror("execve");
			free(command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/*Parent process*/
		wait(NULL);  /*Wait for the child process to finish*/
	}
}

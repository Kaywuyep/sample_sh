#include "shell.h"
/**
 * execute_command - a function that executes the command
 * @command: arguments
 */
void execute_command(char *command)
{
	char *args[MAX_ARGS];
	char *token;
	int num_args = 0;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/*Child process*/
		token = strtok(command, " \n");
		while (token != NULL && num_args < MAX_ARGS - 1)
		{
			args[num_args] = token;
			num_args++;
			token = strtok(NULL, " \n");
		}
		args[num_args] = NULL;

		/* Use execve to execute the command */
		if (execve(args[0], args, NULL) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/*Parent process*/
		wait(NULL);  /*Wait for the child process to finish*/
	}
}
/**
 * exit_builtin - handles exit
 * Return: success
 */
int exit_builtin(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		return (1);
	}
	/*Add more built-in commands here*/

	return (0);
}

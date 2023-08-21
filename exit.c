#include "shell.h"
/**
 * exit_builtin - a function that exits the shell
 * @command: user command
 * @exit_status: the status is an integer used to exit the shell
 * Return: exit
 */
int exit_builtin(const char *command, int *exit_status)
{
	const char *status_str;
	char *endptr;
	int status;

	if (strcmp(command, "exit") == 0)
	{
		*exit_status = 98;  /*Set exit status to 98*/
		return (1);  /*Indicate that the command is an exit command*/
	}
	else if (strncmp(command, "exit ", 5) == 0)
	{
		status_str = command + 5;

		/*Convert status string to integer*/
		status = strtol(status_str, &endptr, 10);

		/*Check for conversion errors*/
		if (*endptr != '\0')
		{
			printf("Invalid exit status: %s\n", status_str);
			return (0);  /*Not an exit command*/
		}

		*exit_status = status;
		return (1);  /*Indicate that the command is an exit command*/
	}
	return (0);  /*Not an exit command*/
}
/**
 * exit_shell - a function that exits the shell
 * @exit_status: the status
 */
void exit_shell(int exit_status)
{
	exit(exit_status);
}

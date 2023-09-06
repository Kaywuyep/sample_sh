#include "shell.h"
/**
 * execute_single_command - Function to execute a single command
 * @command: user input
 * Return: success
 */
int execute_single_command(char *command)
{
	int result;

	printf("Executing command: %s\n", command);
	result = system(command);

	if (WIFEXITED(result))
	{
		return (WEXITSTATUS(result));
	}
	else
	{
		return (-1); /*Command execution failed*/
	}
}
/**
 * handle_logical_and - Function to handle logical AND (&&) operator
 * @command: user input
 * @status: ...
 * Return: ..
 */
int handle_logical_and(char *command, int status)
{
	char *cmd1 = _strtok(command, "&&");
	char *cmd2 = _strtok(NULL, "&&");

	if (status == 0)
	{
		return (execute_single_command(cmd2));
	}
	else
	{
		return (status); /*Skip cmd2*/
	}
}
/**
 * handle_logical_or - Function to handle logical OR (||) operator
 * @command: user input
 * @status: ...
 * Return: ...
 */
int handle_logical_or(char *command, int status)
{
	char *cmd1 = _strtok(command, "||");
	char *cmd2 = _strtok(NULL, "||");

	if (status != 0)
	{
		return (execute_single_command(cmd2));
	}
	else
	{
		return (status); /*skip cmd2*/
	}
}
/**
 * execute_commands_separated - Function to execute commands separated
 * @command: command
 */
void execute_commands_separated(char *command)
{
	char *commands[MAX_COMMAND_LENGTH];
	int num_commands = 0;
	char *token, *input;
	int status, i, exit_status;

	/*Tokenize the input by semicolon*/
	token = _strtok(command, ";");

	while (token != NULL && num_commands < MAX_COMMAND_LENGTH)
	{
		commands[num_commands++] = token;
		token = _strtok(NULL, ";");
	}

	status = 0; /*Success status*/

	for (i = 0; i < num_commands; i++)
	{
		command = commands[i];
		exit_status = 0; /*Status of the current command*/

		if (strstr(command, "&&"))
		{
			/*Handle logical AND (&&) operator*/
			exit_status = handle_logical_and(command, status);
		}
		else if (strstr(command, "||"))
		{
			/*Handle logical OR (||) operator*/
			exit_status = handle_logical_or(command, status);
		}
		else
		{
			/*Execute a single command*/
			exit_status = execute_single_command(command);
		}

		status = exit_status;
	}
}

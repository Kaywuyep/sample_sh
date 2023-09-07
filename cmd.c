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
	int exit_status_cmd1;

	if (status == 0)
	{
		exit_status_cmd1 = execute_single_command(cmd1);
		if (exit_status_cmd1 == 0)
		{
			return (execute_single_command(cmd2));
		}
		else
		{
			return (exit_status_cmd1);
			/*Return the exit status of cmd1*/
		}
	}
	else
	{
		return (status); /* Skip cmd2 */
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
	int exit_status_cmd1;

	if (status != 0)
	{
		exit_status_cmd1 = execute_single_command(cmd1);
		if (exit_status_cmd1 != 0)
		{
			return (execute_single_command(cmd2));
		}
		else
		{
			return (exit_status_cmd1);
			/*Return the exit status of cmd1*/
		}
	}
	else
	{
		return (status); /* Skip cmd2 */
	}
}
/**
 * trim_whitespace  - Function to trim leading and
 * trailing whitespace from a string
 * @str: string to be used
 * Return: string
 */
char *trim_whitespace(char *str)
{
	char *end;

	while (isspace(*str))
	{
		str++;
	}

	if (*str == '\0')
	{ /*All spaces, return an empty string*/
		return (str);
	}

	end = str + strlen(str) - 1;
	while (end > str && isspace(*end))
	{
		end--;
	}

	end[1] = '\0'; /*Null-terminate the trimmed string*/
	return (str);
}
/**
 * execute_commands_separated - Function to execute commands separated
 * by semicolons, && and || logical operators
 * @command: command
 */
void execute_commands_separated(char *command)
{
	char *commands[MAX_COMMAND_LENGTH];
	int num_commands = 0;
	char *token;
	int i, status, exit_status;
	char *cmd;

	/*Tokenize the command by semicolon*/
	token = _strtok(command, ";");
	while (token != NULL && num_commands < MAX_COMMAND_LENGTH)
	{
		commands[num_commands++] = trim_whitespace(token);
		token = _strtok(NULL, ";");
	}

	status = 0; /*Success status*/

	for (i = 0; i < num_commands; i++)
	{
		cmd = commands[i]; /*Update the command to current one*/
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
			exit_status = execute_single_command(cmd);
		}

		status = exit_status;
	}
}

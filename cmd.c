#include "shell.h"
/**
 * handle_logical_and - Function to handle logical AND (&&) operator
 * @command: user input
 * @status: ...
 * Return: ..
 */
int handle_logical_and(char *command, int status)
{
	char *cmd1;
	char *cmd2;
	int exit_status_cmd1;
	int exit_status_cmd2;

	cmd1 = _strtok(command, "&&");

	if (cmd1 != NULL)
	{
		exit_status_cmd1 = execute_single_command(cmd1);
	}
	else
	{
		return (status); /*Skip cmd2*/
	}
	cmd2 = _strtok(NULL, "&&");

	if (cmd2 != NULL)
	{
		exit_status_cmd2 = execute_single_command(cmd2);
		if (exit_status_cmd1 != 0)
		{
			return (exit_status_cmd2);
		}
	}
	else if (exit_status_cmd1 != 0)
	{
		return (exit_status_cmd1); /*Return the exit status of cmd1*/
	}

	/*Handle the case where cmd2 is NULL and exit_status_cmd1 is 0*/
	return (0);
}
/**
 * handle_logical_or - Function to handle logical OR (||) operator
 * @command: user input
 * @status: ...
 * Return: ...
 */
int handle_logical_or(char *command, int status)
{
	char *cmd1;
	char *cmd2;
	int exit_status_cmd1;
	int exit_status_cmd2;

	cmd1 = _strtok(command, "||");

	if (cmd1 != NULL)
	{
		exit_status_cmd1 = execute_single_command(cmd1);
	}
	else
	{
		return (status); /*Skip cmd2*/
	}

	cmd2 = _strtok(NULL, "||");

	if (cmd2 != NULL)
	{
		exit_status_cmd2 = execute_single_command(cmd2);
		if (exit_status_cmd1 != 0)
		{
			return (exit_status_cmd2);
		}
	}
	else if (exit_status_cmd1 != 0)
	{
		return (exit_status_cmd1); /*Return the exit status of cmd1*/
	}

	/*Handle the case where cmd2 is NULL and exit_status_cmd1 is 0*/
	return (0);
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
		cmd = commands[i];/*Update the command to current one*/
		/*exit_status = 0; Status of the current command*/
		exit_status = execute_single_command(cmd);

		if (exit_status != 0)
		{
			/* If a command fails, break out of the loop */
                        status = exit_status;
                        break;
                }

		if (strstr(cmd, "&&"))
		{
			/*Handle logical AND (&&) operator*/
			exit_status = handle_logical_and(cmd, status);
		}
		else if (strstr(cmd, "||"))
		{
			/*Handle logical OR (||) operator*/
			exit_status = handle_logical_or(cmd, status);
		}
		else
		{
			/*Execute a single command*/
			exit_status = execute_single_command(cmd);
		}
		status = exit_status;
	}
}

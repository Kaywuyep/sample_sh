#include "shell.h"
/**
 * _strtok - a non-const copy of the command string
 * @str: string to be used
 * @delim: delimiters
 * Return: _strtok
 */
char *_strtok(char *str, const char *delim);
/**
 * tokenize_command - Tokenize a command and populate an array of arguments
 * @command: the user command
 * @args: char argument
 * Return: total count
 */
int tokenize_command(const char *command, char *args[])
{
	int count = 0;
	char *token;
	char command_copy[MAX_COMMAND_LENGTH]; /*Adjust size as needed*/

	strcpy(command_copy, command);
	token = _strtok(command_copy, " ");

	while (token != NULL && count < MAX_ARGS - 1)
	{
		args[count] = token;
		token = _strtok(NULL, " ");
		count++;
	}
	args[count] = NULL;

	return (count);
}
/**
 * set_env_variable - Set an environment variable or print an error message
 * @variable: name of the environment variable to set
 * @value: value assign to an environment variable
 */
void set_env_variable(const char *variable, const char *value)
{
	if (setenv(variable, value, 1) != 0)
	{
		perror("setenv");
	}
}
/**
 * handle_setenv - Handle the 'setenv' command
 * @command: user command string
 */
void handle_setenv(const char *command)
{
	char *args[MAX_ARGS];
	int count;

	count = tokenize_command(command, args);

	if (count != 3)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return;
	}

	set_env_variable(args[1], args[2]);
}
/**
 * unset_env_variable - Unset an environment variable or print an error message
 * @variable: name of the environment variable to unset
 */
void unset_env_variable(const char *variable)
{
	if (unsetenv(variable) != 0)
	{
		perror("unsetenv");
	}
}
/**
 * handle_unsetenv - Handle the 'unsetenv' command
 * @command: user command string
 */
void handle_unsetenv(const char *command)
{
	char *args[MAX_ARGS];
	int count = tokenize_command(command, args);

	if (count != 2)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return;
	}

	unset_env_variable(args[1]);
}

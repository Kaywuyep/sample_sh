#include "shell.h"
/**
 * setenv_builtin - a function that executes the set_env_variable
 * @command: user command
 * Return: set_env_variable
 */
void setenv_builtin(const char *command)
{
	char *args[MAX_ARGS];
	int count;
	char *command_copy;
	char **tokens;

	command_copy = strdup(command);
	if (command_copy == NULL)
	{
		perror("strdup");
		return;
	}
	tokens = tokening(command_copy, " ");
	if (tokens == NULL)
	{
		free(command_copy);
		return;
	}
	count = 0;
	while (tokens[count] != NULL)
	{
		if (count < MAX_ARGS)
			args[count] = tokens[count];
		count++;
	}

	if (count != 3)
	{
		_fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		free_dp(tokens); /*Free memory and continue*/
		free(command_copy);
		return;
	}
	if (setenv(args[1], args[2], 1) != 0)
	{
		perror("setenv");
	}
	free_dp(tokens);
	free(command_copy);
}
/**
 * unsetenv_builtin - executes the unset_env_builtin command
 * @command: user command
 * Return: unsetenv_variable
 */
void unsetenv_builtin(const char *command)
{
	char *args[MAX_ARGS];
	int count;
	char *command_copy;
	char **tokens;

	command_copy = strdup(command);
	if (command_copy == NULL)
	{
		perror("strdup");
		return;
	}

	tokens = tokening(command_copy, " ");
	if (tokens == NULL)
	{
		free(command_copy);
		return;
	}
	count = 0;
	while (tokens[count] != NULL)
	{
		if (count < MAX_ARGS)
			args[count] = tokens[count];
		count++;
	}

	if (count != 2)
	{
		_fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		free_dp(tokens);
		free(command_copy);
		return;
	}
	if (unsetenv(args[1]) != 0)
	{
		perror("unsetenv");
	}
	free_dp(tokens);
	free(command_copy);
}

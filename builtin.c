#include "shell.h"
/*declaring variables*/
char *_strtok(char *str, const char *delim);
int tokenize_command(const char *command, char *args[]);
void set_env_variable(const char *variable, const char *value);
void unset_env_variable(const char *variable);
/**
 * setenv_builtin - a function that executes the set_env_variable
 * @command: user command
 * Return: set_env_variable
 */
void setenv_builtin(const char *command)
{
	char *args[MAX_ARGS];
	int count;

	count = tokenize_command(command, args);

	if (count != 3)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return;/*returnn an error code*/
	}

	set_env_variable(args[1], args[2]);
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

	count = tokenize_command(command, args);

	if (count != 2)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return;/*return an error code*/
	}

	unset_env_variable(args[1]);
}

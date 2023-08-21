#include "shell.h"
/**
 * execute_builtin_command - Execute a built-in command
 * @args: array of command arguments
 * @count: number of arguments
 */
void execute_builtin_command(char *args[], int count)
{
	if (strcmp(args[0], "setenv") == 0)
	{
		if (count != 3)
		{
			fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		}
		else
		{
			set_env_variable(args[1], args[2]);
		}
	}
	else if (strcmp(args[0], "unsetenv") == 0)
	{
		if (count != 2)
		{
			fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		}
		else
		{
			unset_env_variable(args[1]);
		}
	}
	else
	{
		/*handle other commands or execute external programs*/
	}
}

#include "shell.h"
/**
 * shell_setenv - A function that sets or updates an environment variable.
 * @name: The name of the environment variable.
 * @value: The value to set for the environment variable.
 * Return: 0 on success, -1 on failure.
 */
int shell_setenv(const char *name, const char *value)
{
	if (name == NULL || value == NULL)
	{
		_fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}

	if (setenv(name, value, 1) == -1)
	{
		perror("setenv");
		return (-1);
	}

	return (0);
}

/**
 * shell_unsetenv - A function that unsets an environment variable.
 * @name: The name of the environment variable to unset.
 * Return: 0 on success, -1 on failure.
 */
int shell_unsetenv(const char *name)
{
	if (name == NULL)
	{
		_fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return (-1);
	}

	if (unsetenv(name) == -1)
	{
		perror("unsetenv");
		return (-1);
	}

	return (0);
}


#include "shell.h"

/**
 * builtin_env - A function that prints all environmental variables.
 * @env: The pointer to environmental variables.
 */
void builtin_env(char **env)
{
	size_t i = 0;

	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}

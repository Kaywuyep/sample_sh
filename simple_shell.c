#include "main.h"
/**
 * execute_command - a function that imitates the unix shell
 * @command: const variable
 */
void execute_command(const char *command)
{
	int status = system(command);

	if (status != 0)
	{
		printf("Error executing command: %s\n", command);
	}
}

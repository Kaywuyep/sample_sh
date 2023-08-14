#include "main.h"

/**
 * main - entry point
 *
 * Return: 0
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	size_t command_len;
	int status = 0;

	while (1)
	{
		/*display to prompt*/
		printf("simple_shell:) ");
		fflush(stdout);
		
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n\n\nDisconnecting...\n\n");
			break;/*handle CTRL D*/
		}
		command_len = strlen(command);
		if (command_len > 0 && command[command_len - 1] == '\n')
		{
			command[command_len - 1] = '\0';
		}
		execute_command(command);
		if (status != 0)
		{
			fprintf(stderr, "Error: Command execution failed\n");
		}
	}

	return (0);
}

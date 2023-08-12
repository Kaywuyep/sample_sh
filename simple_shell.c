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
/**
 * main - entry point
 *
 * Return: 0 sucess
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	size_t command_len;

	while (1)
	{
		/*Display the prompt, to request a command*/
		printf("simple_shell:) ");
		fflush(stdout);

		/*Read the user input*/
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			/*Handle end of file (Ctrl+D)*/
			break;
		}

		/*Remove the newline character*/
		command_len = strlen(command);
		if (command_len > 0 && command[command_len - 1] == '\n')
		{
			command[command_len - 1] = '\0';
		}

		/*Execute the command*/
		execute_command(command);
	}

	return (0);
}

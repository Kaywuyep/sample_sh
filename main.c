#include "main.h"
/*declare the display prompt function*/
void display_prompt(void);
/*declare the function to print current environment*/
void print_env(void);
/*declare a function to chect env built in*/
int env_builtin(const char *command);
/**
 * main - entry point
 *
 * Return: 0
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	size_t command_len;

	while (1)
	{
		display_prompt();

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n\n\nDisconnecting...\n\n");
			break;/*handle CTRL+D or EOF*/
		}
		/*remove newline characters*/
		command_len = strlen(command);
		if (command_len > 0 && command[command_len - 1] == '\n')
		{
			command[command_len - 1] = '\0';
		}
		if (exit_builtin(command))
		{
			/*Exit the shell*/
			break;
		}
		else if (env_builtin(command))
		{
			print_env();/*print the current environment*/
		}
		else
		{
			execute_command(command);
		}
	}
	return (0);
}

#include "shell.h"
/**
 * main - entry point
 *
 * Return: cmd
 */
int main(void)
{
	char *command = NULL;
	size_t command_len = 0;
	int n_chars;

	while (1)
	{
		display_prompt();

		n_chars = read_input(&command, &command_len);

		if (n_chars == -1)
		{
			break;
		}

		/*remove newline characters*/
		if (n_chars > 0 && command[n_chars - 1] == '\n')
		{
			command[n_chars - 1] = '\0';
		}
		execute_command(command);
	}
	free(command);
	return EXIT_SUCCESS;
}

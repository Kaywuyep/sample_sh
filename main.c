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
	char **args = NULL;
	int num_args = 0;
	char *path = getenv("PATH");

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
		handle_command(command, &args, &num_args);

		if (num_args > 0)
		{
			if (exit_builtin(args))
			{
				cleanup(command, args, num_args);/**Clean up before exiting*/
				free(command);
				exit(EXIT_SUCCESS);
			}
			else
			{
				execute_command(command, path);
			}
		}

		cleanup(command, args, num_args);
	}
	free(command);
	return (EXIT_SUCCESS);
}

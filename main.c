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
	int num_tok = 0, read_cmd;
	char **argv = NULL;

	while (1)
	{
		display_prompt();

		read_cmd = read_input(&command, &command_len);

		if (read_cmd == -1)
		{
			/*EOF reached, exit the shell*/
			break;
		}
		else if (read_cmd == 0)
		{
			/*Empty line, prompt again*/
			continue;
		}

		num_tok = 0;
		handle_command(command, &argv, &num_tok);

		if (num_tok > 0)
		{
			execute_command(argv);
		}

		cleanup(command, argv);
	}

	return (0);
}

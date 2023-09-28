#include "shell.h"
/**
 * prompt - A function that prints the prompt
 * Return: Nothing.
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "simple_shell $ ", 15);
}


/**
 * handle - A function to handle Ctr + C signal.
 * @signals: The signal to handle.
 * Return: Nothing.
 */
void handle(int signals)
{
	(void)signals;
	write(STDOUT_FILENO, "\nsimple_shell $ ", 17);
}


/**
 * _EOF - A function that checks if buffer is EOF
 * @buffer: The pointer to the input string.
 * Return: Nothing
 */
void _EOF(char *buffer)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(EXIT_SUCCESS);
}

/**
 * is_numeric - function to check if a string is numeric
 * @str: string to be checked
 * Return: status
 */
int is_numeric(const char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
	}
	return (1);
}
/**
 * shell_exit - A function that exits the shell.
 * @command: The pointer to tokenized command.
 * Return: Nothing.
 */
void shell_exit(char **command)
{
	int status = 0;

	if (command[1] == NULL)
	{
		free_dp(command);
		exit(EXIT_SUCCESS);
	}

	if (is_numeric(command[1]))
	{
		status = _atoi(command[1]);
		free_dp(command);
		exit(status);
	}
	else
	{
		_fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", command[1]);
		free_dp(command);
		exit(2);
	}
}

#include "shell.h"
/**
 * display_prompt - a function that displays the shell prompt
 *
 */
void display_prompt(void)
{
	printf("simple_shell:) ");
	fflush(stdout);
}
/**
 * read_input -  a function that reads each line of input
 * @command: pointer to the string line
 * @command_len: number of bytes read
 * Return: lines read
 */
int read_input(char **command, size_t *command_len)
{
	ssize_t num_chars;

	num_chars = getline(command, command_len, stdin);

	if (num_chars == -1)
	{
		printf("\n\n\nDisconnecting...\n\n");
		return (-1); /*EOF or handle CTRL+D*/
	}

	/*Remove newline characters*/
	if (num_chars > 0 && (*command)[num_chars - 1] == '\n')
	{
		(*command)[num_chars - 1] = '\0';
	}

	if (strlen(*command) == 0)
	{
		return (0); /*handle endpty line*/
	}

	return (1); /*Signal to process the command*/
}
/**
 * handle_command - a function that handles input
 * @command: user command
 * @args: argument
 * @num_tok: number of token
 */
void handle_command(char *command, char ***args, int *num_tok)
{
	const char *delim = " \n";
	char *token;
	int i = 0;
	char *command_copy;

	(void)delim;

	command_copy = strdup(command);/*Create a copy of input for processing*/

	token = strtok(command, " \n");
	while (token != NULL)
	{
		(*num_tok)++;
		token = strtok(NULL, " \n");
	}

	(*args) = malloc(sizeof(char *) * (*num_tok + 1));
	if (*args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	token = strtok(command_copy, " \n");
	i = 0;
	while (token != NULL)
	{
		(*args)[i] = strdup(token);
		i++;
		token = strtok(NULL, " \n");
	}
	(*args)[i] = NULL;

	free(command_copy);
}
/**
 * cleanup - a function that cleans up
 * @command: user input
 * @args: argument
 * @num_args: number of arguments passed
 */
void cleanup(char *command, char **args, int num_args)
{
	int i;

	(void)command;

	for (i = 0; i <= num_args; i++)
	{
		free(args[i]);
	}
	free(args);
}

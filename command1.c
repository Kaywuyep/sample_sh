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
 * @argv: argument
 * @num_tok: number of token
 */
void handle_command(char *command, char ***argv, int *num_tok)
{
	const char *delim = " \n";
	char *token;
	int i = 0;
	char *command_copy;

	command_copy = strdup(command);/*Create a copy of input for processing*/

	token = strtok(command, delim);
	while (token != NULL)
	{
		(*num_tok)++;
		token = strtok(NULL, delim);
	}

	(*argv) = malloc(sizeof(char *) * (*num_tok + 1));

	token = strtok(command_copy, delim);
	while (token != NULL)
	{
		(*argv)[i] = strdup(token);
		i++;
		token = strtok(NULL, delim);
	}
	(*argv)[i] = NULL;

	free(command_copy);
}
/**
 * cleanup - a function that cleans up
 * @command: user input
 * @argv: argument
 */
void cleanup(char *command, char **argv)
{
	int i;

	free(command);
	for (i = 0; argv[i] != NULL; i++)
	{
		free(argv[i]);
	}
	free(argv);
}

#include "main.h"

/**
 * main - entry point
 *
 * @argv: argument vector
 * Return: 0
 */
int main(char **argv)
{
	char command[MAX_COMMAND_LENGTH];
	size_t command_len;
	ssize_t nchars;
	char *copy_command = NULL;
	const char *delim = " \n";
	int num_tokens = 0, i;
	char *token;

	while (1)
	{
		printf("simple_shell:) ");
		fflush(stdout);
		nchars = fgets(command, sizeof(command), stdin);
		if (nchars == NULL)
		{
			printf("\n\n\nDisconnecting...\n\n");
			break;
		}
		copy_command = malloc(sizeof(char) * nchars);
		if (copy_command == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		strcpy(copy_command, command);
		token = strtok(command, delim);
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;
		argv = malloc(sizeof(char *) * num_tokens);
		token = strtok(copy_command, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		printf("%s\n", command);
		command_len = strlen(command);
		if (command_len > 0 && command[command_len - 1] == '\n')
		{
			command[command_len - 1] = '\0';
		}
		execute_command(command);
		free(argv);
		free(command);
		free(copy_command);
	}
	return (0);


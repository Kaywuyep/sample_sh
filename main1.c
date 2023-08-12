#include "main.h"
/**
 * main - entry point
 *
 * Return: 0
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char **argv = NULL;
	const char *delim = " \n";
	size_t command_len;
	ssize_t nchars;
	char *token;
	int num_tokens = 0, i;

	while (1)
	{
		printf("simple_shell:) ");
		fflush(stdout);

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n\n\nDisconnecting...\n\n");
			break;
		}
		66
			command_len = strlen(command);
		if (command_len > 0 && command[command_len - 1] == '\n')
		{
			command[command_len - 1] = '\0';
		}
		token = strtok(command, delim);

		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}

		argv = malloc(sizeof(char *) * (num_tokens + 1));
		if (argv == NULL)
		{
			perror("tsh: memory allocation error");
			return -1;
		}

		token = strtok(command, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = strdup(token);
			if (argv[i] == NULL)
			{
				perror("tsh: memory allocation error");
				return -1;
			}
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		printf("%s\n", command);
		/*Call the execute_command function with the command*/
		execute_command(command);

		for (i = 0; i < num_tokens; i++) {
			free(argv[i]);
		}
		free(argv);
	}

	return (0);
}

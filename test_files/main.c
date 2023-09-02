#include "test.h"

int main(void)
{
	char command[] = "ls -l -a";
	const char *delim = " ";

	char *tokens[MAX_TOKENS];
	int num_tokens = 0;
	int i;
	char *token = _strtok(command, delim);

	while (token != NULL && num_tokens < MAX_TOKENS)
	{
		tokens[num_tokens++] = token;
		token = _strtok(NULL, delim);
	}

	printf("Tokens:\n");
	for (i = 0; i < num_tokens; i++)
	{
		printf("%s\n", tokens[i]);
	}

	return (0);
}

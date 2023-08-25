#include "shell.h"
/**
 * main - entry point
 *
 * Return: ...
 */

int main(void)
{
	char *lineptr;
	size_t n = 0; 

	while(1)
		display_prompt();
	getline(&lineptr, &n, stdin);
	printf("%s\n", lineptr);

	free(lineptr);

}

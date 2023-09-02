#include "test.h"

int main(void)
{
	const char *delim = " ,";/*Test with space and comma as delimiters*/

	/*Test input strings*/
	char input1[] = "apple,banana,orange";
	char input2[] = "one two three";
	char input3[] = "   leading spaces";
	char input4[] = "trailing spaces   ";
	char input5[] = "  two  spaces  ";

	char *token;

	/*Test case 1*/
	token = _strtok(input1, delim);
	while (token != NULL)
	{
		printf("Token: %s\n", token);
		token = _strtok(NULL, delim);
	}

	/*Test case 2*/
	token = _strtok(input2, delim);
	while (token != NULL)
	{
		printf("Token: %s\n", token);
		token = _strtok(NULL, delim);
	}

	/*Test case 3*/
	token = _strtok(input3, delim);
	while (token != NULL)
	{
		printf("Token: %s\n", token);
		token = _strtok(NULL, delim);
	}

	/*Test case 4*/
	token = _strtok(input4, delim);
	while (token != NULL)
	{
		printf("Token: %s\n", token);
		token = _strtok(NULL, delim);
	}

	/*Test case 5*/
	token = _strtok(input5, delim);
	while (token != NULL)
	{
		printf("Token: %s\n", token);
		token = _strtok(NULL, delim);
	}

	return (0);
}

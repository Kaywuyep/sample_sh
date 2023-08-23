#include "shell.h"
/**
 * _getline - a function that reads a line
 * @lineptr: the string line
 * @n: the number of bytes read
 * @stream: the ..
 * Return: line read
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t buffer = *n;
	int c;
	size_t i = 0;
	char *newlineptr;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}

/*Allocate memory for the initial line*/
    if (*lineptr == NULL)
    {
        *lineptr = (char *)malloc(buffer);
        if (*lineptr == NULL)
	{
            return (-1); /*Memory allocation error*/
        }
    }

	while ((c = fgetc(stream)) != EOF)
	{
		if (i + 1 >= buffer)
		{
			buffer *= 2; /*Double the buffer size*/
			newlineptr = (char *)realloc(*lineptr, buffer);
			if (newlineptr == NULL)
			{
				free(*lineptr);
				return (-1); /*Memory allocation error*/
			}
			*lineptr = newlineptr;
			*n = buffer;
		}

		(*lineptr)[i++] = c;

		if (c == '\n')
		{
			break;
		}
	}

	if (i == 0)
	{
		free(*lineptr);
		return (-1); /*No characters read*/
	}

	(*lineptr)[i] = '\0'; /*Null-terminate the string*/
	newlineptr = *lineptr;
	return (i); /*Return the number of characters read*/
}

#include "shell.h"
/**
 * find_start - Function to find the start of the next token
 * @str: a pointer to the string
 * @delim: pointers to the string of delimiters
 *
 * Return: the string pointer to the first non-delimiter character
 */
char *find_start(char *str, const char *delim)
{
	while (*str != '\0' && strchr(delim, *str) != NULL)
		str++;
	return (str);
}
/**
 * find_end - Function to find the end of the current token
 * @str: a pointer to a string
 * @delim: ptr to the string of delimiters
 *
 * Return: the string ptr to the character just after the token's end
 */
char *find_end(char *str, const char *delim)
{
	while (*str != '\0' && strchr(delim, *str) == NULL)
		str++;
	return (str);
}
/**
 * _strtok - Custom strtok function
 * @str: a pointer to the input string
 * @delim: a pointer to the delimiter string
 * @saveptr:  that keeps track of the current position in the string
 *
 * Return: the start of the token
 */
char *_strtok(const char *str, const char *delim, char **saveptr)
{
	char *start, *end;
	char buffer[MAX_COMMAND_LENGTH];

	if (str == NULL && *saveptr == NULL)/*end of the str has been reached*/
		return (NULL);

	if (str != NULL)
		/**saveptr = str;updates the saveptr with the current*/
		/*position of the input string*/
		strcpy(buffer, str);
	*saveptr = buffer; /*Now you can update saveptr*/

	start = find_start(*saveptr, delim);/*use the find_start to determine*/
	/*the start of the next token*/
	if (*start == '\0')
		return (NULL);

	end = find_end(start, delim);/*use find_end to fnd end of current tok*/
	if (*end != '\0')
	{
		*end++ = '\0';
		*saveptr = end;
	}
	else/*If the end of the token is the end of the string*/
		/*it simply updates saveptr to point to the null terminator.*/
	{
		*saveptr = end; /*Point to the null terminator*/
	}
	return (start);
}

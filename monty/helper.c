#include "monty.h"
/**
 * _isdigit - Checks for a digit 0 through 9
 * @str: variable
 * Return: 0 or 1
 */
int _isdigit(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);  /*Not a valid integer if the string is empty or NULL*/

	while (*str)
	{
		if (!isdigit(*str) && (*str != '-' && *str != '+'))
			return (0);  /* Not a digit or a valid sign character*/
		str++;
	}

	return (1);  /*All characters are valid digits or signs*/
}

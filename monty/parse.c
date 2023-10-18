#include "monty.h"

glob_t global = {NULL, NULL};
/**
 * handle_command - Read file
 * @argv: Arguments
 * Return: Nothing
 */
void handle_command(char *argv)
{
	int count = 0, result = 0;
	size_t bufsize = 0;
	char *arguments = NULL, *item = NULL;
	stack_t *stack = NULL;

	global.fd = fopen(argv, "r");
	if (global.fd)
	{
		while (getline(&global.line, &bufsize, global.fd) != -1)
		{
			count++;
			arguments = strtok(global.line, " \n\t\r");
			if (arguments == NULL)
				continue;
			else if (*arguments == '#')
				continue;
			item = strtok(NULL, " \n\t\r");
			result = get_opc(&stack, arguments, item, count);
			if (result == 1)
				push_error(stack, count);
			else if (result == 2)
				ins_error(count, arguments);
		}
		free(global.line);
		free_dlistint(stack);
		fclose(global.fd);
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
}

/**
 * get_opc - function to handle the opcode
 * @stack: is a stack or queue
 * @arg: is a parameter
 * @item: is a parameter
 * @count: is a line command
 * Return: nothing
 */
int get_opc(stack_t **stack, char *arg, char *item, int count)
{
	int i = 0;

	instruction_t op[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}};

	while (op[i].opcode)
	{
		if (!strcmp(arg, op[i].opcode))
		{
			if (!strcmp(arg, "push"))
			{
				if (item == NULL)
				{
					dprintf(STDERR_FILENO, "L%d: usage: push integer\n", count);
					exit(EXIT_FAILURE);
				}
				if (_isdigit(item) == 1)
					value = atoi(item);
				else
				{
					dprintf(STDERR_FILENO, "L%d: usage: push integer\n", count);
					exit(EXIT_FAILURE);
				}
			}
			op[i].f(stack, (unsigned int)count);
			break;
		}
		i++;
	}
	if (!op[i].opcode)
		return (2);

	return (0);
}
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

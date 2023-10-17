#include "monty.h"
/**
 * free_dlistint - Free a list.
 * @stack: Head node.
 * Return: Nothing.
 */
void free_dlistint(stack_t *stack)
{
	stack_t *current = NULL;

	current = stack;

	if (current != NULL)
	{
		free_dlistint(current->next);
		free(current);
	}
}

/**
 * clean_stack - Frees mallocs and close de files
 * @stack: Stack
 */
void clean_stack(stack_t *stack)
{
	while (stack != NULL)
	{
		stack_t *temp = stack;
		stack = stack->next;
		free(temp);
	}

	if (global.fd != NULL)
		fclose(global.fd);
}

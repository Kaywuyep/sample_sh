#include "monty.h"
/**
 * _pall - prints all the values on the stack
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		dprintf(STDOUT_FILENO, "%d\n", current->n);
		current = current->next;
	}
}

/**
 * _push - pushes an element to the stack
 * @stack: double pointer to the stack
 * @line_number: line number in the file
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	(void)line_number;

	new_node = create_node(value);

	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * create_node - create new node
 * @value: is data value
 * Return: new node
 */
stack_t *create_node(int value)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->next = NULL;
	new_node->prev = NULL;

	return (new_node);
}
/**
 * _pint - prints the value at the top of the stack.
 * @stack: Stack list
 * @line_number: Number of the line
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		clean_stack(*stack);  /*Clean up the stack before exiting*/
		exit(EXIT_FAILURE);
	}

	dprintf(STDOUT_FILENO, "%d\n", (*stack)->n);
}
/**
 * _pop - removes the top element of the stack.
 * @stack: Stack list
 * @line_number: Number of the line
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		clean_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}

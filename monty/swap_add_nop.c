#include "monty.h"
/**
 * _swap - swaps the top two elements of the stack.
 * @stack: Stack
 * @line_number: Number of the line
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		clean_stack(*stack);  /*Clean up the stack before exiting*/
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}


/**
 * _add - function add two integer
 * @stack: Stack list
 * @line_number: Number of the line
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line_number);
		clean_stack(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	_pop(stack, line_number);  /*Remove the top element*/
}


/**
 * _nop - function void
 * @stack: Stack list
 * @line_number: Number of the line
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	/*do nothing*/
}

#include "monty.h"
/**
 * push_error - handle push error
 * @stack: is a stack or queue
 * @count: is a line command
 */
void push_error(stack_t *stack, int count)
{
	dprintf(STDERR_FILENO, "L%u: usage: push integer\n", count);
	free_dlistint(stack);
	exit(EXIT_FAILURE);
}

/**
 * ins_error - Error handler
 * @count: is a line command
 * @item: opcode
 */
void ins_error(int count, char *item)
{
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", count, item);
	exit(EXIT_FAILURE);
}

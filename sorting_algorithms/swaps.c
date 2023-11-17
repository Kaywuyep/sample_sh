#include "sort.h"

/**
 * swap - a function that swaps two variables
 * @a: variable
 * @b: variable
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * swap_nodes - Swaps a node with its previous node in a doubly linked list
 * @list: Pointer to the head of the doubly linked list
 * @node: Pointer to the node to be swapped with its previous node
 */
void swap_nodes(listint_t **list, listint_t *node)
{
	listint_t *prev, *prev_prev, *next;

	if (node == NULL || node->prev == NULL)
		return;

	prev = node->prev;
	prev_prev = prev->prev;
	next = node->next;

	if (prev_prev != NULL)
	{
		prev_prev->next = node;
	}
	else
	{
		*list = node;
	}

	node->prev = prev_prev;
	node->next = prev;
	prev->prev = node;
	prev->next = next;

	if (next != NULL)
	{
		next->prev = prev;
	}
}

/**
 * swap_shell_sort - Swaps the positions of two elements in an array
 * @array: Pointer to the array
 * @a: Index of the first element
 * @b: Index of the second element
 */
void swap_shell_sort(int *array, size_t a, size_t b)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

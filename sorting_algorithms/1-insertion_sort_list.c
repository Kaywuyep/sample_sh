#include "sort.h"

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
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		temp = current;
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			swap_nodes(list, temp);
			print_list(*list);
		}
		current = current->next;
	}
}


#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 *                      using the Cocktail shaker sort algorithm.
 * @list: Pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start = *list;
	listint_t *end = NULL;

	if (list == NULL || *list == NULL)
		return;

	do {
		swapped = 0;

		while (start->next != end)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start->next);
				print_list(*list);
				swapped = 1;
			}
			else
				start = start->next;
		}

		if (swapped == 0)
			break;

		swapped = 0;
		end = start;

		while (start->prev != NULL)
		{
			if (start->n < start->prev->n)
			{
				swap_nodes(list, start);
				print_list(*list);
				swapped = 1;
			}
			else
				start = start->prev;
		}
	} while (swapped);
}

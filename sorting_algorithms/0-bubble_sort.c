#include "sort.h"
/**
 * bubble_sort - a function that compares two elmts and swaps
 * @array: array of elmets to be sorted
 * @size:m size of the array
 *
 * Description: this is a function that compares two adacent elements
 * and swaps then untill the are in the intended order which could
 * be either ascending or decending order
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			if (array[j] > array[j + 1] && array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
	print_array(array, size);
}

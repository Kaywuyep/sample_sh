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
 * lomuto_partition - Lomuto partition scheme for quicksort
 * @array: Pointer to the array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 * 
 * Return: Index of the pivot element after partitioning
 */
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t i = low - 1;
	ssize_t j;

	for (j = low; j <= high - 1; ++j)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (i + 1 != high)
	{
		swap(&array[i + i], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function algorithim for quicksort
 * @array: Pointer to the array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, ssize_t low, ssize_t high, size_t size)
{
	size_t pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm (Lomuto partition scheme)
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

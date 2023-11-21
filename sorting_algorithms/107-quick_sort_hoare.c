#include "sort.h"

/**
 * swap_quick - Swaps the positions of two elements in an array.
 * @array: The array.
 * @idx1: Index of the first element.
 * @idx2: Index of the second element.
 */
void swap_quick(int *array, ssize_t idx1, ssize_t idx2)
{
	int temp;

	temp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = temp;
}

/**
 * hoare_partition - Implements the Hoare partition scheme for quicksort.
 * @array: The array to be partitioned.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 *
 * Return: The position of the last element in the sorted partition.
 */
int hoare_partition(int *array, int low, int high, int size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do
		{
			i++;
		} while (array[i] < pivot);

		do
		{
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return i;

		swap_quick(array, i, j);
		print_array(array, size);
	}
}

/**
 * quicksort - Recursive function to implement the quicksort algorithm.
 * @array: The array to be sorted.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 */
void quicksort(int *array, ssize_t low, ssize_t high, int size)
{
	ssize_t position = 0;

	if (low < high)
	{
		position = hoare_partition(array, low, high, size);
		quicksort(array, low, position - 1, size);
		quicksort(array, position, high, size);
	}
}

/**
 * quick_sort_hoare - Prepares the terrain for the quicksort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}


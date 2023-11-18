#include "sort.h"
/**
 * merge - Merge two subarrays of the array.
 * @array: The array to be sorted.
 * @temp: Temporary array for merging.
 * @left: Start index of the left subarray.
 * @mid: Middle index.
 * @right: End index of the right subarray.
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	for (i = left, j = mid, k = 0; i < mid && j < right; k++)
	{
		if (array[i] <= array[j])
		{
			temp[k] = array[i];
			i++;
		}
		else
		{
			temp[k] = array[j];
			j++;
		}
	}

	while (i < mid)
	{
		temp[k] = array[i];
		i++;
		k++;
	}

	while (j < right)
	{
		temp[k] = array[j];
		j++;
		k++;
	}

	for (i = 0, k = left; k < right; i++, k++)
		array[k] = temp[i];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_sort_recursive - Recursively divides the array and merges subarrays.
 * @array: The array to be sorted.
 * @temp: Temporary array for merging.
 * @left: Start index of the subarray.
 * @right: End index of the subarray.
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
	size_t mid;

	if (right - left > 1)
	{
		mid = left + (right - left) / 2;
		merge_sort_recursive(array, temp, left, mid);
		merge_sort_recursive(array, temp, mid, right);
		merge(array, temp, left, mid, right);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_sort_recursive(array, temp, 0, size);

	free(temp);
}

#include "sort.h"

/**
 * find_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int find_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *  using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sort_done, max, i;

	if (array == NULL || size < 2)
		return;

	sort_done = malloc(sizeof(int) * size);
	if (sort_done == NULL)
		return;
	max = find_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sort_done);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;/*Initialize count array with all zeros*/
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;/*Store the count of each element*/
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];/*Stor d cummulativ count of ech arr*/
	print_array(count, max + 1);
	/*Find the index of each elmtt of the original array in count array*/
	/*and place the elements in output array*/
	for (i = 0; i < (int)size; i++)
	{
		sort_done[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}
	/*Copy the sorted elements into original array*/
	for (i = 0; i < (int)size; i++)
		array[i] = sort_done[i];
	free(sort_done);
	free(count);
}

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
 * radix_countSort - Sort the significant digits of an array of integers
 * in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @exp: exp is 10^i
 * @buff: A buffer to store the sorted array.
 */
void radix_countSort(int *array, size_t size, int exp, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	/*initialize the count array to zero*/
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max, exp, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = find_max(array, size);
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		radix_countSort(array, size, exp, buff);
		print_array(array, size);
	}

	free(buff);
}

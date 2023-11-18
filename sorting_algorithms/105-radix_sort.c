#include "sort.h"
/**
 * radix_count_sort - A function to do counting sort of arr[] according to
 * the digit represented by exp.
 * @arr: array
 * @n: size of the array
 * @exp: exp is 10^i
 * @output: array to save the temporary values
 */
void radix_count_sort(int *arr, size_t n, int exp, int *result)
{
	int i;
	int count[10] = {0};

	for (i = 0; i < (int)n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	/* Build the output array */
	for (i = n - 1; i >= 0; i--)
	{
		result[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	/*Copy the output array to arr[], so that arr[] now*/
	/*contains sorted numbers according to current digit*/
	for (i = 0; i < (int)n; i++)
		arr[i] = result[i];
}

/**
 * radix_sort - The main function to that sorts arr[]
 * of size n using Radix Sort
 * @array: array
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int exp, max = 0;
	int *result = '\0'; /*result output array should be n(size)*/

	if (array == '\0' || size < 2)
		return;

	max = find_max(array, size);
	result = malloc(size * sizeof(int));
	if (result == '\0')
		return;
	/*
	 * Do counting sort for every digit. Note that instead
	 * of passing digit number, exp is passed. exp is 10^i
	 * where i is current digit number
	 */
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		radix_count_sort(array, size, exp, result);
		print_array(array, size);
	}
	free(result);
}

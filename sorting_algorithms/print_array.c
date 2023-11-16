#include "sort.h"
/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}

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

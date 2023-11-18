#include "sort.h"
/**
 * max_heapify - Fixes a max heap at given index.
 * @array: Array to be heapified.
 * @size: Size of the array for printing.
 * @idx: Index to start heapifying.
 * @n: Size of the array to heapify.
 */
void max_heapify(int *array, size_t size, int idx, size_t n)
{
	int largest = idx;/*Initialize largest as root*/
	int left = 2 * idx + 1;	 /* left = (idx << 1) + 1*/
	int right = 2 * idx + 2; /* right = (idx + 1) << 1*/

	/*check if left child of root exists and is greater than root*/
	if (left < (int)n && array[left] > array[largest])
		largest = left;

	/*check if right child of root exists and is greater*/
	/*than the largest so far*/
	if (right < (int)n && array[right] > array[largest])
		largest = right;

	/* Change root, if neccesary*/
	if (largest != idx)
	{
		swap(&array[idx], &array[largest]);
		print_array(array, size);
		max_heapify(array, size, largest, n);
	}
}
/**
 * heap_sort - Sorts an array using the heap sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 * Description: Builds a max heap and repeatedly extracts the maximum
 * element to sort the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;
	
	if (array == '\0' || size < 2)
		return;

	for (i = (size - 2) / 2; i >= 0; --i)
		max_heapify(array, size, i, size);
	for (i = (size - 1); i > 0; --i)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		max_heapify(array, size, 0, i);
	}
}

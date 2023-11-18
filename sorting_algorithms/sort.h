#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

#define UP 1
#define DOWN 0


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void swap(int *a, int *b);
void swap_shell_sort(int *array, size_t a, size_t b);
void swap_nodes(listint_t **list, listint_t *node);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size);
void quick_sort_recursive(int *array, ssize_t low, ssize_t high, size_t size);
int find_max(int *array, int size);
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right);
void merge(int *array, int *temp, size_t left, size_t mid, size_t right);
void max_heapify(int *array, size_t size, int idx, size_t n);
void radix_countSort(int *array, size_t size, int sig, int *buff);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);


#endif

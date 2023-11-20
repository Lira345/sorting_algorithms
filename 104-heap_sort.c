#include "sort.h"

/**
 * swap - swaps 2 integers
 * @a: the first integer
 * @b: the second integer
 * Return: void
*/
void swap(int *a, int *b)
{
	int res = *a;

	*a = *b;
	*b = res;
}

/**
 * heapify - maintain the max heap property for the tree (array)
 * @array: the array in consideration
 * @total_size: the total size of the array as it's needed to print the arr
 * @size: the active size of the heap (array) (as we are deleting elements)
 * @i: the index of the element
 * Return: void
*/
void heapify(int *array, size_t total_size, size_t size, size_t n)
{
	size_t large = n, left, right;

	left = 2 * (n + 1) - 1;
	right = 2 * (n + 1);

	if (left < size && array[left] > array[large])
	{
		large = left;
	}
	if (right < size && array[right] > array[large])
	{
		large = right;
	}
	if (n != large)
	{
		swap(&array[n], &array[large]);
		print_array(array, total_size);
		heapify(array, total_size, size, large);
	}
}

/**
 * heap_sort - sorts an array according to heap sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
*/
void heap_sort(int *array, size_t size)
{
	size_t n;

	if (size == 0)
		return;
	for (n = (size / 2) - 1; ; n--)
	{
		heapify(array, size, size, n);
		if (n == 0)
			break;
	}
	for (n = size; n > 0; n--)
	{
		if (n - 1 != 0)
		{
			swap(&array[n - 1], &array[0]);
			print_array(array, size);
		}
		heapify(array, size, n - 1, 0);
	}
}

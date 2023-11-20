#include "sort.h"
#include <stdio.h>

/**
 * bitonic_compare - Sorts the values in a sub-array with respect to,
 * the bitonic sort algorithms
 * @up: Pointer to direction of sorting
 * @array: sub-array to sort.
 * @size: size of the sub-array
 * Return: void.
 */
void bitonic_compare(char up, int *array, size_t size)
{
	size_t n;
	size_t dist;
	int swp;

	dist = size / 2;
	for (n = 0; n < dist; n++)
	{
		if ((array[n] > array[n + dist]) == up)
		{
			swp = array[n];
			array[n] = array[n + dist];
			array[n + dist] = swp;
		}
	}
}

/**
 * bitonic_merge - the recursive function that merges 2 sub-arrays.
 * @up: Pointer to direction of sorting.
 * @array: sub-array to sort
 * @size: size of the sub-array
 * Return: void
 */
void bitonic_merge(char up, int *array, size_t size)
{
	if (size < 2)
		return;
	bitonic_compare(up, array, size);
	bitonic_merge(up, array, size / 2);
	bitonic_merge(up, array + (size / 2), size / 2);
}

/**
 * bit_sort - the recursive function using the Bitonic sort algorithms.
 * @up: Pointer to direction of sorting.
 * @array: sub-array to sort.
 * @size: size of the sub-array
 * @t: total size of the original array
 * Return: void.
 */
void bit_sort(char up, int *array, size_t size, size_t t)
{
	if (size < 2)
		return;
	printf("Merging [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);
	bit_sort(1, array, size / 2, t);
	bit_sort(0, array + (size / 2), size / 2, t);
	bitonic_merge(up, array, size);
	printf("Result [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);
}

/**
 * bitonic_sort - Sorts the array of integers in ascending/increasing order
 * Using the bitonic sort algorithms
 * @array: array to sort
 * @size: size of the array
 * Return: void.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bit_sort(1, array, size, size);
}

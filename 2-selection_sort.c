#include "sort.h"

/**
 * swap - swap or switches the 2 given values.
 * @a: first int
 * @b: second int
 * Return: void.
 */
void swap(int *a, int *b)
{
	int res;

	res = *a;
	*a = *b;
	*b = res;
}

/**
 * get_min_index - finds the minimum index for a sub array.
 * @array: Pointer to array to sort
 * @start: Pointer to the starting index of the sub array.
 * @size: Pointer to the size of the array
 * Return: min_index.
 */
size_t get_min_index(int *array, int start, size_t size)
{
	size_t n, min_index;
	int min_val;

	min_val = array[start];
	min_index = start;
	for (n = start + 1; n < size; n++)
	{
		if (array[n] < min_val)
		{
			min_val = array[n];
			min_index = n;
		}
	}
	return (min_index);
}
/**
 * selection_sort - sorts the array using the selection sort algorithm.
 * @array: Pointer to array to sort
 * @size: Pointr to the size of the array.
 * Return: void.
 */
void selection_sort(int *array, size_t size)
{
	size_t n, min_index;

	for (n = 0; n < size; n++)
	{
		min_index = get_min_index(array, n, size);
		if (n != min_index)
		{
			swap(&array[n], &array[min_index]);
			swap(&array[n], &array[min_index]);
		}
	}
}

#include "sort.h"

/**
 * swap - swaps 2 ints
 * @a: the first integer
 * @b: the second integer
 * Return: void
*/
void swap(int *a, int *b)
{
	int res;

	res = *a;
	*a = *b;
	*b = res;
}

/**
 * get_gap - gets the gap using Knuth sequence
 * @size: the size of the array
 * Return: the gap
*/
size_t get_gap(size_t size)
{
	size_t gap = 1;

	while (gap < size)
	{
		gap = 3 * gap + 1;
	}
	gap = (gap - 1) / 3;
	return (gap);
}
/**
 * shell_sort - sorts the array using the shell sort
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
*/
void shell_sort(int *array, size_t size)
{
	size_t gap, m, n;

	gap = get_gap(size);
	for (; gap >= 1; gap = (gap - 1) / 3)
	{
		for (m = gap; m < size; m++)
		{
			for (n = m - gap; ; n = n - gap)
			{
				if (array[n + gap] < array[n])
					swap(&array[n], &array[n + gap]);
				else
					break;
				if (gap > n)
					break;
			}
		}
		print_array(array, size);
	}
}

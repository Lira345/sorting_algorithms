#include "sort.h"

/**
 * swap - Swaps 2 numbers
 * @a: the 1st number
 * @b: the second number
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
 * bubble_sort - sorts an array using bubble sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
*/

void bubble_sort(int *array, size_t size)
{
	size_t n, m;

	for (n = 0; n < size; n++)
	{
		for (m = 0; m < (size - n - 1); m++)
		{
			if (array[m + 1] < array[m])
			{
				swap(&array[m + 1], &array[m]);
				print_array(array, size);
			}
		}
	}
}

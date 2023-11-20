#include "sort.h"

/**
 * swap - swap or switches the 2 given ints
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
 * partition - splits the array into 2 parts, where fulcrum is in the middle.
 * @array: Pointer to the array to sort.
 * @size: Pointer to the size of the array.
 * @low: the lower index in the sub array to sort
 * @high: the higher index in the sub array to sort.
 * Return: The index of the pivot/fulcrum.
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot;
	int n = low;
	int m;

	pivot = array[high];
	for (m = low; m < high; m++)
	{
		if (array[m] <= pivot)
		{
			if (m != n)
			{
				swap(&array[m], &array[n]);
				print_array(array, size);
			}
			n++;
		}
	}
	if (n != high)
	{
		swap(&array[high], &array[n]);
		print_array(array, size);
	}
	return (n);
}

/**
 * quick_sorting - the quick sort algorithm.
 * @array: Pointer to the array to sort.
 * @size: Pointer to the size of the array
 * @low: the lower index in the sub array to sort.
 * @high: the higher value in the sub array to sort
 * Return: void.
 */
void quick_sorting(int *array, size_t size, int low, int high)
{
	int part;

	if (low >= high)
	{
		return;
	}
	part = partition(array, size, low, high);
	quick_sorting(array, size, low, part - 1);
	quick_sorting(array, size, part + 1, high);
}

/**
 * quick_sort - a function for the quick sort algorithm.
 * @array: Pointer to the array to sort.
 * @size: the size of the array
 * Return: void.
 */
void quick_sort(int *array, size_t size)
{
	quick_sorting(array, size, 0, size - 1);
}

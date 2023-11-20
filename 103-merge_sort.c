#include "sort.h"

/**
 * print_array_from - Prints an array of int
 * @array: Pointer to an array to be printed.
 * @size: Pointer to number of elements in @array.
 */
void print_array_from(const int *array, size_t size, size_t start)
{
	size_t n;

	n = start;
	while (array && n < size)
	{
		if (n > start)
			printf(", ");
		printf("%d", array[n]);
		++n;
	}
	printf("\n");
}

/**
 * merge - merges the 2 sub arrays in a sorted way.
 * @array: Pointer to the array to sort.
 * @left: Pointer to the start of the sub array
 * @mid: the middle mid element in the sub array
 * @right: the ending index of the sub array (excluded)
 * @temp_arr: the temp array to store in
 * Return: void
 */
void merge(int *array, size_t left, size_t mid, size_t right, int *temp_arr)
{
	size_t n = left;
	size_t m = mid;
	size_t c = left;

	printf("Merging...\n");
	printf("[left]: ");
	print_array_from(array, mid, left);
	printf("[right]: ");
	print_array_from(array, right, mid);
	while (n < mid && m < right)
	{
		if (array[n] <= array[m])
		{
			temp_arr[c] = array[n];
			n++;
		}
		else
		{
			temp_arr[c] = array[m];
			m++;
		}
		c++;
	}
	while (n < mid)
	{
		temp_arr[c] = array[n];
		n++;
		c++;
	}
	while (m < right)
	{
		temp_arr[c] = array[m];
		m++;
		c++;
	}
	for (c = left; c < right; c++)
		array[c] = temp_arr[c];
	printf("[Done]: ");
	print_array_from(array, right, left);
}

/**
 * merge_sorting - implements the merge sort of algorithm.
 * @array: Pointer to the array to sort.
 * @left: the start index of the sub array.
 * @right: the end index of the sub array (excluded)
 * @temp_arr: temp array to store resuls in
 * Return: void
 */
void merge_sorting(int *array, size_t left, size_t right, int *temp_arr)
{
	int mid;

	if (left + 1 >= right)
		return;

	mid = left + (right - left) / 2;
	merge_sorting(array, left, mid, temp_arr);
	merge_sorting(array, mid, right, temp_arr);
	merge(array, left, mid, right, temp_arr);
}

/**
 * merge_sort - a function for merge sorting.
 * @array: Pointer to the array to sort.
 * @size: the size of the array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *temp_arr;

	temp_arr = malloc(size * sizeof(int));
	if (temp_arr == NULL)
		return;
	merge_sorting(array, 0, size, temp_arr);
	free(temp_arr);
}

#include "sort.h"


/**
 * get_max - Gets the max num in an array
 * @array: the array to search in
 * @size: the size of the array
 * Return: the max number
*/
int get_max(int *array, size_t size)
{
	int num = 0;
	size_t n;

	for (n = 0; n < size; n++)
	{
		if (array[n] > num)
			num = array[n];
	}
	return  (num);
}

/**
 * count_sort - sorts digit based on position value according to count sort
 * @array: the array to sort
 * @size: the size of the array
 * @pos: the postion to consider (units, tens, hunderds, ...etc)
 * Return: void
*/
void count_sort(int *array, size_t size, int pos)
{
	int count[10] = {0}, *temp_array;
	size_t n;

	temp_array = malloc(size * sizeof(int));
	if (temp_array == NULL)
		return;
	for (n = 0; n < size; n++)
		count[(array[n] / pos) % 10]++;
	for (n = 1; n < 10; n++)
		count[n] += count[n - 1];
	for (n = size - 1; ; n--)
	{
		temp_array[--count[(array[n] / pos) % 10]] = array[n];
		if (n == 0)
			break;
	}
	for (n = 0; n < size; n++)
		array[n] = temp_array[n];
	free(temp_array);
}

/**
 * radix_sort - sorts an array according to radix sort
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
*/
void radix_sort(int *array, size_t size)
{
	int pos, max_num;

	if (size == 0)
		return;
	max_num = get_max(array, size);
	for (pos = 1; max_num / pos > 0; pos *= 10)
	{
		count_sort(array, size, pos);
		print_array(array, size);
	}
}

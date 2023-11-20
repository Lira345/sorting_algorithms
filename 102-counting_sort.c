#include "sort.h"

/**
 * counting_sort - sorts the array according to count sort algorithm.
 * @array: Pointer to the array to sort.
 * @size: Pointer to the size of the array.
 * Return: void.
 */
void counting_sort(int *array, size_t size)
{
	int *count;
	int *tempArray;
	int c;
	size_t n;

	if (size == 0)
		return;
	c = array[0];
	for (n = 1; n < size; n++)
	{
		if (array[n] > c)
			c = array[n];
	}
	count = malloc((c + 1) * sizeof(int));
	if (count == NULL)
		return;
	tempArray = malloc(size * sizeof(int));
	if (tempArray == NULL)
	{
		free(count);
		return;
	}
	for (n = 0; n <= (size_t) c; n++)
		count[n] = 0;
	for (n = 0; n < size; n++)
		count[array[n]]++;
	for (n = 1; n <= (size_t) c; n++)
		count[n] += count[n - 1];
	print_array(count, c + 1);
	for (n = 0; n < size; n++)
		tempArray[--count[array[n]]] = array[n];
	for (n = 0; n < size; n++)
		array[n] = tempArray[n];
	free(count);
	free(tempArray);
}

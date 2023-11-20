#include "sort.h"

/**
 * selection_sort -  function that use selection sort algorithm
 * @array: an array to sort
 * @size: the size of the array
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	int aux = 0;
	size_t n = 0, m = 0, pos = 0;

	if (array == NULL || size == 0)
		return;

	for (; n < size - 1; n++)
	{
		pos = n;
		for (m = n + 1; m < size; m++)
		{
			if (array[m] < array[pos])
				pos = m;
		}
		if (pos != n)
		{
			aux = array[n];
			array[n] = array[pos];
			array[pos] = aux;
			print_array(array, size);
		}
	}
}

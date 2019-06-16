#include "sort.h"

/**
 * selection_sort - sorts an array using selection sort algorithm
 * @array: integer array
 * @size: size of the array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t current, nSorted = 0, count;
	int temp, min, x;

	if (size == 1 || size == 0)
		return;

	while (nSorted < (size - 1))
	{
		min = array[nSorted];
		current = nSorted;
		x = 0;
		while (current < size)
		{
			if (array[current] < min)
				count = current, min = array[current], x = -1;
			    current++;
		}
		if (x == -1)
		{
			temp = array[nSorted];
			array[nSorted] = min;
			array[count] = temp;
			print_array(array, size);
		}
			nSorted++;
	}
}

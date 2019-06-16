#include "sort.h"

/**
 * bubble_sort - sort an array of integers using Bubble sort algorithm
 * @array: pointer to array to be sorted
 * @size: size of array
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t idx = 0, temp, check;

	while (1)
	{
		check = 0;
		while (idx < size)
		{
			if (array[idx] > array[idx + 1])
			{
				temp = array[idx + 1];
				array[idx + 1] = array[idx];
				array[idx] = temp, check = 1;
				print_array(array, size);
			}
			if ((idx + 1) == (size - 1))
				break;
			idx++;
		}
		idx = 0;
		if (check == 0)
			break;
	}
}

#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: pointer to the array of integers to be sorted
 * @size: size of array of integers to be sorted
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int save;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j + 1] < array[j])
			{
				save = array[j];
				array[j] = array[j + 1];
				array[j + 1] = save;
				print_array(array, size);
			}
		}
	}
}

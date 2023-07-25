#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using
 * the Shell sort algorithm with the Knuth sequence.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t wait;
	size_t i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	wait = 1;

	/*Generate Knuth sequence with the first element greater than size*/
	while (wait < size)
	{
		wait = wait * 3 + 1;
	}
	wait = (wait - 1) / 3;

	while (wait > 0)
	{
		for (i = wait; i < size; i++)
		{
			temp = array[i];
			j = i;
			for (; j >= wait && array[j - wait] > temp; j -= wait)
			{
				array[j] = array[j - wait];
			}
			array[j] = temp;
		}
		/* Print the array after each time interval is decreased*/
		print_array(array, size);
	}
}

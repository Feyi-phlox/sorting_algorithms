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
	size_t wt;
	size_t i, j;
	int tp;

	if (array == NULL || size < 2)
		return;

	wt = 1;

	/*Generate Knuth sequence with the first element greater than size*/
	while (wt < size / 3)
	{
		wt = wt * 3 + 1;
	}
	wt = (wt - 1) / 3;

	while (wt > 0)
	{
		for (i = wt; i < size; i++)
		{
			tp = array[i];
			for (j = i; j >= wt && array[j - wt] > tp; j -= wt)
			{
				array[j] = array[j - wt];
			}
			array[j] = tp;
		}
		/* Print the array after each time interval is decreased*/
		print_array(array, size);
	}
}

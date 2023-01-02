#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the shell sort algorithm
 *
 * @array: pointer to the firs element of the array
 * @size: size of @array
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1, i, j;
	int value;

	while (interval < size / 3)
	{
		interval = interval * 3 + 1;
	}

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			value = array[i];

			j = i;
			while (j > interval - 1 && array[j - interval] >= value)
			{
				array[j] = array[j - interval];
				j -= interval;
			}

			array[j] = value;
		}

		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}

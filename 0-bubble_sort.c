#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the bubble sort algorithm
 *
 * @array: array to be sorted
 * @size: size of @array
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t initial_size, new_size, i;

	initial_size = size;
	do {
		new_size = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				temp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = temp;
				new_size = i;
				print_array(array, initial_size);
			}
		}
		size = new_size;
	} while (size > 1);
}

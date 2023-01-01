#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the quick sort algorithm
 *
 * @array: array of integers
 * @size: size of @array
 */
void quick_sort(int *array, size_t size)
{
	int pivot, temp;
	size_t left, j;

	if (array == NULL || size < 2)
		return;

	pivot = array[size - 1];
	for (j = 0; j < size - 1 && array[j] < pivot; j++)
	;
	left = j;
	if (j != size - 1)
		j++;

	for (; j < size - 1; j++)
	{
		if (array[j] < pivot)
		{
			temp = array[j];
			array[j] = array[left];
			array[left] = temp;
			left++;
			print_array(array, size);
		}
	}
	array[size - 1] = array[left];
	array[left] = pivot;

	quick_sort(array, left);
	if (left != size - 1)
		quick_sort(array + left + 1, size - left - 1);
}

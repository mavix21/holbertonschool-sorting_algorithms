#include "sort.h"

/**
 * swap - swap the values of two int variables
 *
 * @x: pointer to first integer
 * @y: pointer to second integer
 */
void swap(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}

/**
 * partition - pivots the array around the last element of the @array (high)
 * i.e rearranges the @array in such a way all the elements before the pivot
 * are less or equal than it, and all the elements after the pivot are greater
 * or equal than it
 *
 * @array: pointer to first element of the subarray
 * @low: index of the first element of the subarray
 * @high: index of the last element of the subarray
 * @size: original size of the array
 *
 * Return: index of the pivot element after the rearrangenment
 */
size_t partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int left, j;

	for (j = low; j < high && array[j] <= pivot; j++)
	;
	left = j;
	if (j != high)
		j++;

	for (; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swap(&array[left], &array[j]);
			left++;
			print_array(array, size);
		}
	}


	if (left < high)
	{
		array[high] = array[left];
		array[left] = pivot;
		print_array(array, size);
	}

	return (left);
}

/**
 * quick_sort_recursion - sorts the subarrays recursively
 *
 * @array: pointer to first element of the subarray
 * @low: index of the first element of the subarray
 * @high: index of the last element of the subarray
 * @size: original size of the array
 */
void quick_sort_recursion(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);
		quick_sort_recursion(array, low, pivot_index - 1, size);
		quick_sort_recursion(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the quick sort algorithm
 *
 * @array: array of integers
 * @size: size of @array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursion(array, 0, size - 1, size);
}

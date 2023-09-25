#include "sort.h"

/**
 * quick_sort - sorts an array of integers using quick sort algorithm
 * @array: array to be sorted
 * @size: the array's size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	
	quicksort_recursive(array, 0, size - 1, size);
}

/**
 * partition - partitions the array and returns the pivot index
 * @array: the array to be partitioned
 * @low: the low index of the array
 * @high: the high index of the array
 * @size: the size of the array
 * Return: pivot index
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, temp, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort_recursive - recursively sorts an array using quick sort
 * @array: the array to be sorted
 * @low: the low index of the array
 * @high: the high index of the array
 * @size: the size of the array
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		quicksort_recursive(array, low, pi - 1, size);
		quicksort_recursive(array, pi + 1, high, size);
	}
}

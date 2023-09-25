#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: the array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int j, swapped = 0;
	size_t i, temp_size = size;

	if (array == NULL)
		return;

	while (size != 0)
	{
		for (i = 0 ; i < size - 1 ; i++)
		{
			if (array[i] > array[i + 1])
			{
				j  = array[i];
				array[i] = array[i + 1];
				array[i + 1] = j;
				print_array(array, temp_size);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
		size--;
	}
}

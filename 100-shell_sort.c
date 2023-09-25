#include "sort.h"

/**
 * shell_sort - sorts array of integers using shell sort
 * @array: array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	int ssize = (int)size;
	int gap = 1, outer, inner, insertion_value;

	while (gap < ssize / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (outer = gap ; outer < ssize ; outer++)
		{
			insertion_value = array[outer];
			inner = outer;
			while (inner > gap - 1 && array[inner - gap] >= insertion_value)
			{
				array[inner] = array[inner - gap];
				inner = inner - gap;
			}
			array[inner] = insertion_value;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}

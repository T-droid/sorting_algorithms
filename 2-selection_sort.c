#include "sort.h"

/**
 * _swap - swap two numbers
 *
 * @b: second integer
 * @a: first integer
 **/
void _swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * selection_sort - sort array using selection sort algorithm
 *
 * @size: array size
 * @array: the array to sort
 **/

void selection_sort(int *array, size_t size)
{
	unsigned int i;
	unsigned int j;
	unsigned int min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
				min = j;
		}
		if (min != i)
		{
			_swap(&array[i], &array[min]);
			print_array(array, size);
		}
	}

}

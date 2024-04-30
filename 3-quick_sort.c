#include "s_header.h"

/**
 * partition - partition scheme lomuto
 * @array: arr to sort
 * @low: l-index
 * @high: h-index
 * @size: arr size
 * Return: pivot index
*/
int partition(int *array, int low, int high, size_t size)
{
	int pvVar = array[high], i = low - 1, temp;
	int j = low;

	while (j < high)
	{
		if (array[j] <= pvVar)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
		}
		j++;
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	if (i + 1 != j)
	{
		print_array(array, size);
	}
	return (i + 1 + (1 - 1));
}

/**
 * quick_s - funct help
 * @array: arr to sort
 * @low: l-index
 * @high: h-index
 * @size: arr size
*/

void quick_s(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_indexVar = partition(array, low, high, size);

		quick_s(array, low, pivot_indexVar - 1, size);
		quick_s(array, pivot_indexVar + 1, high, size);
	}
}

/**
 * quick_sort - arr of integers
 * using the Quick sort algorithm
 * @array: arr to sort
 * @size: arr size
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
	{
		return;
	}
	quick_s(array, 0, size - 1, size);
}
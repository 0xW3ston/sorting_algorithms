#include "s_header.h"

/**
*swap - the positions of two elements
*@array: arr
*@item1: arr elmnt
*@item2: arr elmnt
*/
void swap(int *array, int item1, int item2)
{

	int tempVar;

	tempVar = array[item1];
	array[item1] = array[item2];
	array[item2] = tempVar;
}
/**
 * shell_sort - knTH sequence sort
 * @size: arr size
 * @array: list with numbers
 */
void shell_sort(int *array, size_t size)
{
	size_t ligVar = 1, j, index = 0;

	if (array == NULL || size < 2)
		return;
	while (ligVar < size / 3)
		ligVar = 3 * ligVar + 1;
	while (ligVar >= 1)
	{
		for (j = ligVar; j < size; j++)
			for (index = j; index >= ligVar &&
			 (array[index] < array[index - ligVar]); index -= ligVar)
				swap(array, index, index - ligVar);
		print_array(array, size);
		ligVar /= 3;
	}
}

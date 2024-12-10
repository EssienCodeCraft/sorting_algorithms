#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of integers
 *
 */
void selection_sort(int *array, size_t size)
{
	int sort;
	size_t x, y, min;

	for (x = 0; x < size - 1; x++)
	{
		min = x;
		for (y = x + 1; y < size; y++)
		{
			if (array[y] < array[min])
			{
				min = y;
			}
		}
		if (min != x)
		{
			sort = array[x];
			array[x] = array[min];
			array[min] = sort;
			print_array((const int *)array, size);
		}
	}
}

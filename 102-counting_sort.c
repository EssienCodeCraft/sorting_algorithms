#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Entry Point
 * @array: pointer to array
 * @size: size of the array
 *
 */
void counting_sort(int *array, size_t size)
{
	int a, b, *count, *main;
	size_t x;

	if (!array || size < 2)
		return;
	a = array[0];
	for (x = 0; x < size; x++)
	{
		if (array[x] > a)
			a = array[x];
	}
	count = calloc((a + 1), sizeof(int));
	for (x = 0; x < size; x++)
	{
		count[array[x]]++;
	}
	for (b = 1; b < a; b++)
	{
		count[b + 1] += count[b];
	}
	print_array(count, a + 1);
	main = malloc(sizeof(int) * size);
	for (x = 0; x < size; x++)
	{
		count[array[x]]--;
		main[count[array[x]]] = array[x];
	}
	for (x = 0; x < size; x++)
	{
		array[x] = main[x];
	}
	free(main);
	free(count);
}

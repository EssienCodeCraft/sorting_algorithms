#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * check_tree - Entry Point
 * @array: pointer to array
 * @size: size of the pointer
 * @size_init: original size of the array
 * @i: index as a root of the tree
 *
**/
void check_tree(int *array, size_t size_init, size_t size, size_t i)
{

	int x, arm1, arm2;
	size_t b1, b2;

	b1 = i * 2 + 1;
	b2 = b1 + 1;
	arm1 = array[b1];
	arm2 = array[b2];
	if (((b1 < size) && (b2 < size) &&
		(arm1 >= arm2 && arm1 > array[i]))
		|| ((b1 == size - 1) && arm1 > array[i]))
	{
		x = array[i];
		array[i] = arm1;
		array[b1] = x;
		print_array(array, size_init);
	}
	else if ((b1 < size) && (b2 < size) &&
		(arm2 > arm1 && arm2 > array[i]))
	{
		x = array[i];
		array[i] = arm2;
		array[b2] = x;
		print_array(array, size_init);
	}
	if (b1 < size - 1)
		check_tree(array, size_init, size, b1);
	if (b2 < size - 1)
		check_tree(array, size_init, size, b2);
}

/**
 * heap_sort - Entry Point
 * @array: pointer to array
 * @size: size of the pointer
 *
**/
void heap_sort(int *array, size_t size)
{
	size_t i, size_init = size;
	int x;

	if (!array)
		return;
	for (i = 0; i < size / 2 ; i++)
	{
		check_tree(array, size_init, size, size / 2 - 1 - i);
	}
	for (i = 0; i < size_init - 1; i++)
	{
		x = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = x;
		print_array(array, size_init);
		check_tree(array, size_init, size - i - 1, 0);
	}

}

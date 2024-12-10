#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
*swap - Entry Point
*@array: array
*@unit1: array element
*@unit2: array element
*/
void swap(int *array, ssize_t unit1, ssize_t unit2)
{
	int temp;

	temp = array[unit1];
	array[unit1] = array[unit2];
	array[unit2] = temp;
}

/**
 *hoare_partition - Entry Point
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: size array
 *Return: return the position of the last element sorted
 */
int hoare_partition(int *array, int first, int last, int size)
{
	int present = first - 1, now = last + 1;
	int pivot = array[last];

	while (1)
	{

		do {
			present++;
		} while (array[present] < pivot);
		do {
			now--;
		} while (array[now] > pivot);
		if (present >= now)
			return (present);
		swap(array, present, now);
		print_array(array, size);
	}
}

/**
 *qs - Entry Point
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: array size
 */
void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = hoare_partition(array, first, last, size);
		qs(array, first, position - 1, size);
		qs(array, position, last, size);
	}
}

/**
 *quick_sort_hoare - Entry Point
 *@array: array
 *@size: array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * copy_func - Entry Point
 * @src: source buffer
 * @dest: destination buffer
 * @size: size of buffers
 *
 */
void copy_func(int *src, int *dest, int size)
{
	int x;

	for (x = 0; x < size; x++)
		dest[x] = src[x];
}

/**
 * merge_func - Entry Point
 * @array: first set of data
 * @buff: second set of data
 * @minL: lower range of first set of data
 * @maxL: upper range of first set of data
 * @minH: lower range of second set of data
 * @maxH: upper range of second set of data
 *
 * Return: No Return
 */
void merge_func(int *array, int *buff, int minL, int maxL, int minH, int maxH)
{
	int x = minL, y = minH, z = minL;

	while (x <= maxL || y <= maxH)

		if (x <= maxL && y <= maxH)
			if (buff[x] <= buff[y])
				array[z] = buff[x], z++, x++;
			else
				array[z] = buff[y], z++, y++;

		else if (x > maxL && y <= maxH)
			array[z] = buff[y], z++, y++;
		else
			array[z] = buff[x], z++, x++;
}

/**
 * printcheck - Entry Point
 * @array: array of data to be print
 * @r1: start of range
 * @r2: end of range
 *
 * Return: No Return
 */
void printcheck(int *array, int r1, int r2)
{
	int x;

	for (x = r1; x <= r2; x++)
	{
		if (x > r1)
			printf(", ");
		printf("%d", array[x]);
	}
	printf("\n");
}

/**
 * split - Entry Point
 * @array: array of data to be split
 * @buff: auxiliary array of data for merging
 * @min: min range of data in array
 * @max: max range of data in array
 * @size: size of total data
 *
 * Return: No Return
 */
void split(int *array, int *buff, int min, int max, int size)
{
	int mid, tmax, minL, maxL, minH, maxH;

	if ((max - min) <= 0)
		return;

	mid = (max + min + 1) / 2;
	tmax = max;
	max = mid - 1;

	minL = min;
	maxL = max;

	split(array, buff, min, max, size);

	min = mid;
	max = tmax;

	minH = min;
	maxH = max;

	split(array, buff, min, max, size);

	printf("Merging...\n");
	printf("[left]: ");

	printcheck(array, minL, maxL);

	printf("[right]: ");

	printcheck(array, minH, maxH);
	merge_func(array, buff, minL, maxL, minH, maxH);
	copy_func(array, buff, size);

	printf("[Done]: ");
	printcheck(array, minL, maxH);
}

/**
 * merge_sort - Entry Point
 *
 * @array: array of data to be sorted
 * @size: size of data
 *
 * Return: No Return
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	copy_func(array, buff, size);

	split(array, buff, 0, size - 1, size);

	free(buff);
}

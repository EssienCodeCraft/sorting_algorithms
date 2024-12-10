#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Entry Point
 * @arr: array
 * @item1: item one
 * @item2: item two
 * @order: 1: ascending order, 0 descending order
 */
void swap(int arr[], int item1, int item2, int order)
{
	int temp;

	if (order == (arr[item1] > arr[item2]))
	{
		temp = arr[item1];
		arr[item1] = arr[item2];
		arr[item2] = temp;
	}
}

/**
 * merge - Entry Point
 * @arr: array
 * @low: first element
 * @nelemnt: elements number
 * @order: 1: ascending order, 0 descending order
 */
void merge(int arr[], int low, int nelemnt, int order)
{
	int mid, x;

	if (nelemnt > 1)
	{
		mid = nelemnt / 2;
		for (x = low; x < low + mid; x++)
			swap(arr, x, x + mid, order);
		merge(arr, low, mid, order);
		merge(arr, low + mid, mid, order);
	}
}

/**
 * bitonicsort - Entry Point
 * @arr: array
 * @low: first element
 * @nelemnt: number of elements
 * @order: 1: ascending order, 0 descending order
 * @size: array lenght
 */
void bitonicsort(int arr[], int low, int nelemnt, int order, int size)
{
	int mid;

	if (nelemnt > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		mid = nelemnt / 2;
		bitonicsort(arr, low, mid, 1, size);
		bitonicsort(arr, low + mid, mid, 0, size);
		merge(arr, low, nelemnt, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
	}
}

/**
 * bitonic_sort - Entry Point
 * @array: array
 * @size: array lenght
 */
void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;
	bitonicsort(array, 0, size, order, size);
}

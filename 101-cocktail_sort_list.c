#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * _swap - Entry Point
 * @node: node to be swapped
 * @list: double link list head
 *
 * Return: No Return
 */

void _swap(listint_t **node, listint_t **list)
{
	listint_t *sort = *node, *sort2, *sort3;


	if (!(*node)->prev)
		*list = (*node)->next;

	sort = sort3 = *node;
	sort2 = sort->next;

	sort->next = sort2->next;
	sort3 = sort->prev;
	sort->prev = sort2;
	sort2->next = sort;
	sort2->prev = sort3;

	if (sort2->prev)
		sort2->prev->next = sort2;


	if (sort->next)
		sort->next->prev = sort;

	*node = sort2;

}

/**
 * cocktail_sort_list - Entry Point
 * @list: head of list to be sortered (Double Linked List)
 *
 * Return: No Return
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *top, *main;
	int x = 0, n = -1, m = -1;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;

	top = *list;
	while (m >= n)
	{
		n++;
		while (top->next && x != m)
		{
			if (top->n > top->next->n)
			{
				main = top;
			       _swap(&main, list);
			       print_list(*list);
			       top = main;
			}

			x++;
			top = top->next;
		}

		if (n == 0)
			m = x;
		m--;
		while (top->prev && x >= n)
		{
			if (top->n < top->prev->n)
			{
				main = top->prev;
				_swap(&main, list);
				print_list(*list);
				top = main->next;
			}
			x--;
			top = top->prev;
		}
	}
}

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_nodes - function that swaps two nodes in a listint_t doubly-linked list
 * @h: A pointer to the head of the doubly-linked list.
 * @node1: A pointer to the first node to swap.
 * @node2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*h = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 *                     in ascending order  using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *rep, *ins, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (rep = (*list)->next; rep != NULL; rep = temp)
	{
		temp = rep->next;
		ins = rep->prev;
		while (ins != NULL && rep->n < ins->n)
		{
			swap_nodes(list, &ins, rep);
			print_list((const listint_t *)*list);
		}
	}
}

#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: Double pointer to the head of the linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *SwapNode, *NextSwap;

	if (list == NULL || *list == NULL)
		return;

	SwapNode = (*list)->next;
	while (SwapNode != NULL)
	{
		NextSwap = SwapNode->next;
		while (SwapNode->prev != NULL && SwapNode->prev->n > SwapNode->n)
		{
			SwapNode->prev->next = SwapNode->next;
			if (SwapNode->next != NULL)
				SwapNode->next->prev = SwapNode->prev;
			SwapNode->next = SwapNode->prev;
			SwapNode->prev = SwapNode->next->prev;
			SwapNode->next->prev = SwapNode;
			if (SwapNode->prev == NULL)
				*list = SwapNode;
			else
				SwapNode->prev->next = SwapNode;
			print_list(*list);
		}
		SwapNode = NextSwap;
	}
}

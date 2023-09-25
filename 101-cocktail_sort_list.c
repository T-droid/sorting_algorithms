#include "sort.h"

/**
 * cocktail_sort_list - sorts a linked list using cocktail shaker sorting
 * @list: double pointer to the linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *start, *end;
	int swapped = 1;

	if (!list || !(*list) || !((*list)->next))
		return;
	start = NULL;
	end = NULL;

	while (swapped)
	{
		swapped = 0;
		current = *list;
		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(current, current->next, list);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->next;
		}

		if (!swapped)
			break;

		swapped = 0;
		end = current;

		while (current->prev != start)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(current->prev, current, list);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->prev;
		}

		start = current;
	}
}

/**
 * swap_nodes - swaps two nodes in a linked list
 * @node1: first node
 * @node2: second node
 * @list: pointer to the head of the list
 */
void swap_nodes(listint_t *node1, listint_t *node2, listint_t **list)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

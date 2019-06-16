#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list with insertion sort
 * @list: list to sort
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *back, *forward;

	if (list == NULL || *list == NULL)
		return;
	if ((*list)->next == NULL)
		return;
	back = *list;
	forward = (*list)->next->next;
	current = (*list)->next;
	while (1)
	{
		while (current->n < back->n)
		{
			if (current->next != NULL)
				current->next->prev = back;
			if (back->prev != NULL)
				back->prev->next = current;
			current->prev = back->prev;
			back->next = current->next, current->next = back;
			back->prev = current, back = current->prev;
			while ((*list)->prev != NULL)
				*list = (*list)->prev;
			print_list(*list);
			if (back == NULL)
				break;
		}
		if (forward == NULL)
			break;
		if (forward->next == NULL)
		{
			current = forward;
			back = forward->prev, forward = forward->next;
		}
		else
		{
			current = forward->prev, back = current->prev;
			forward = forward->next, current = current->next;
			back = back->next;
		}
	}
}

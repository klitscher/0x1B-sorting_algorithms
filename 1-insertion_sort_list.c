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
	current = *list;
	back = *list;
	forward = *list;
	while(forward != NULL)
	{
		forward = current->next->next;
		current = current->next;
		while (back != NULL)
		{
			if (current->n < back->n)
			{
				if(back->prev == NULL)
				{
					current->prev = NULL;
					current->next = back;
					back->prev = current;
					back->next = forward;
					forward->prev = back;
				}
				else
				{
					current->prev = NULL;
					current->next = back;
					back->prev->next = current;
					back->prev = current;
					back->next = forward;
					if(forward != NULL)
						forward->prev = back;
				}
				while((*list)->prev != NULL)
					*list = (*list)->prev;
				print_list(*list);
			}
			current = back;
			back = back->prev;
		}
		current = forward;
		if (current != NULL)
		{
			back = current->prev;
			forward = current->next;
		}
	}
}

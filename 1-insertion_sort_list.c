#include "sort.h"

/**
 * insertion_sort_list - sorts a double linked list of integers
 * in ascending order using the insertion sort algorithm
 *
 * @list: address of pointer to the fist element of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *temp;

	if (list == NULL || *list == NULL)
		return;

	node = *list;
	while (node != NULL)
	{
		temp = node;
		while (temp->prev != NULL && temp->n < (temp->prev)->n)
		{
			(temp->prev)->next = temp->next;
			if (temp->next != NULL)
				(temp->next)->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = (temp->prev)->prev;
			(temp->next)->prev = temp;
			if (temp->prev != NULL)
				(temp->prev)->next = temp;
			else
				*list = temp;

			print_list(*list);
		}
		node = node->next;
	}
}

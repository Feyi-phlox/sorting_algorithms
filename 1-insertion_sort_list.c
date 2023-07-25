#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the first node of the list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp;
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;

	while (current != NULL)
	{
		tmp = current;

		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			/* Swap nodes */
			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;

			tmp->prev->next = tmp->next;
			tmp->next = tmp->prev;
			tmp->prev = tmp->prev->prev;

			if (tmp->prev != NULL)
				tmp->prev->next = tmp;

			if (tmp->next == NULL)
				*list = tmp;

			/* Print the list after swapping elements */
			print_list(*list);

			tmp = tmp->prev;
		}

		current = current->next;
	}
}

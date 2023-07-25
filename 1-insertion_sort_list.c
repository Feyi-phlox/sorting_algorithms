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

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			/* Swap nodes */

			if (temp->next != NULL)
				temp->next->prev = temp->prev;

			temp->prev->next = temp->next;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;

			if (temp->prev != NULL)
				temp->prev->next = temp;

			if (temp->next == NULL)
				*list = temp;

			/* Print the list after swapping elements */
			print_list(*list);
		}

		current = current->next;
	}
}

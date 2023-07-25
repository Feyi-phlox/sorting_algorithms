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

		while (current->prev != NULL && (current->n > current->prev->n))
		{
			/* Swap nodes */
			temp = current->next;
			current->next = temp->next;
			temp->prev = current->prev;

			if (current->next != NULL)
				current->next->prev = temp;

			if (temp->prev != NULL)
				temp->prev->next = current;
			current->next = temp;
			temp->prev = current;

			if (temp->next != NULL)
				current = temp->next;
			else
				*list = temp;

			/* Print the list after swapping elements */
			print_list(*list);
		}

		current = current->next;
	}
}

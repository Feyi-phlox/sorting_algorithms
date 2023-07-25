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

		while (current->next != NULL && (current->n > current->next->n))
		{
			/* Swap nodes */
			temp = current->next;
			current->next = temp->next;
			temp->prev = current->prev;

			if (current->prev != NULL)
				current->prev->next = temp;

			if (temp->next != NULL)
				temp->next->prev = current;
			current->prev = temp;
			temp->next = current;

			if (temp->prev != NULL)
				current = temp->prev;
			else
				*list = temp;

			/* Print the list after swapping elements */
			print_list(*list);
		}

		current = current->next;
	}
}

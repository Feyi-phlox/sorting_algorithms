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
	listint_t *insert;
	int value;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		insert = current->prev;
		value = current->n;

		while (insert != NULL && insert->n > value)
		{
			insert->next->n = insert->n;
			insert = insert->prev;
		}

		if (insert == NULL)
		{
			(*list)->n = value;
		}
		else
		{
			insert->next->n = value;
		}
		temp = *list;
		while (temp)
		{
			temp = temp->next;
			print_list(*list);
		}
		current = current->next;
	}
}

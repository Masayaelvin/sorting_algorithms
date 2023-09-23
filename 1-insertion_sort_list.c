#include "sort.h"

/**
 * insertion_sort_list - function that sorts
 * a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head = NULL;

	if (!list || !(*list))
		return;

	head = *list; /*first node of the list*/
	while (head && head->next)
	{
		if (head->n > head->next->n) /*comparison of values*/
		{
			_swap(&head, list);
			print_list(*list);

			while (head && head->prev)
			{
				if (head->n < head->prev->n)
				{
					head = head->prev;
					_swap(&(head), list);
					print_list(*list);
					head = head->next;
				}
				head = head->prev;
			}
		}
		head = head->next;
	}
}

/**
 * _swap - exchange elements
 * @list: list
 * @node: node of list
 */
void _swap(listint_t **node, listint_t **list)
{
	listint_t *aux = *node, *aux2, *aux3;

	if (!(*node)->prev)
		*list = (*node)->next;

	aux2 = aux->next;
	aux->next = aux2->next;
	aux3 = aux->prev;
	aux->prev = aux2;
	aux2->next = aux;
	aux2->prev = aux3;

	if (aux2->prev)
		aux2->prev->next = aux2;

	if (aux->next)
		aux->next->prev = aux;

	*node = aux2;
}

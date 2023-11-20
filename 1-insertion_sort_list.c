#include "sort.h"

/**
 * swap_node - Swaps 2 nodes
 * @a: the 1st node
 * @b: the second node
 * Return: the smaller node address
*/
listint_t *swap_node(listint_t *a, listint_t *b)
{

	if (a == NULL || b == NULL)
		return (b);
	a->next = b->next;
	if (a->next != NULL)
	{
		a->next->prev = a;
	}
	b->prev = a->prev;
	if (b->prev != NULL)
	{
		b->prev->next = b;
	}
	b->next = a;
	a->prev = b;
	return (b);
}
/**
 * insertion_sort_list - sorts a list using insertion sort algorithm
 * @list: the list to sort
 * Return: void
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *n, *m;

	if ((list == NULL || (*list == NULL)))
	{
		return;
	}
	for (n = *list; n != NULL;)
	{
		m = n->prev;
		n = n->next;
		while (m != NULL)
		{
			if (m->next->n < m->n)
			{
				m = swap_node(m, m->next);
				if (m->prev == NULL)
				{
					*list = m;
				}
				m = m->prev;
				print_list(*list);
			}
			else
			{
				break;
			}
		}
	}

}

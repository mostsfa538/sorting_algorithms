#include "sort.h"


/**
 * insertion_sort_list  - insertion_sort_list
 * @list: doubly liked list
 *
 */

void insertion_sort_list(listint_t **list)
{
    listint_t *head, *prev;
	int value;

	if (!list || !(*list)->next || !(*list))
		return;

	head = *list;
	while (head)
	{
		prev = head->prev;
		value = head->n;
		while (prev && prev->n > value)
		{
			list_swap(prev, head, list);
			print_list(*list);
			prev = head->prev;
		}
		head = head->next;
	}
}

/**
 * list_swap - swaps 2 nodes in a doubly linked list
 * @head: head of list
 * @a: first node
 * @b: first node
 */
void list_swap(listint_t *a, listint_t *b, listint_t **head)
{
	listint_t *tmp1 = NULL, *tmp2 = NULL;

	if (a == NULL || b == NULL)
		return;
	tmp1 = a->prev;
	tmp2 = b->next;

	if (tmp1)
		tmp1->next = b;
	if (tmp2)
		tmp2->prev = a;
	a->next = tmp2;
	a->prev = b;
	b->next = a;
	b->prev = tmp1;

	if (tmp1 == NULL)
		*head = b;
}

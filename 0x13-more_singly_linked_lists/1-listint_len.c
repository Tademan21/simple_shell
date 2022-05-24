#include <stdlib.h>
#include "lists.h"

/**
 * listint_len - find the number of elements in a linked list
 * @h: pointer to the head of the list
 * Return: the number of elements
 */
size_t listint_len(const listint_t *h)
{
	if (h == NULL)
		return (0);

	h = h->next;

	return (1 + listint_len(h));
}

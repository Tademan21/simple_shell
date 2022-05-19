#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all the elements of a list_t list
 * @h: pointer to the head node
 * Return: number of nodes as size_t
 *
 */
size_t print_list(const list_t *h)
{
	if (h == NULL)
		return (0);

	if (h->str == NULL)
		printf("[0] (nil)\n");

	else
		printf("[%d] %s\n", h->len, h->str);

	h = h->next;

	return (1 + print_list(h));
}

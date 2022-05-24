#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_ptrlist2 - frees a ptrhold list
 * @head: a pointer to the start of the list
 * Return: nothing.
 */
void free_ptrlist2(ptrhold *head)
{
	ptrhold *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * add_node2 - adds a new node at the beginning of a list
 * @head: a pointer to a pointer to the start of the list
 * @hold: the integer to be inserted in the new node
 * Return: address of the new element
 */
ptrhold *add_node2(ptrhold **head, listint_t *hold)
{
	ptrhold *new;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(*new));

	if (new == NULL)
	{
		free_ptrlist2(*head);
		return (NULL);
	}

	new->hold = hold;
	new->next = *head;
	*head = new;

	return (*head);
}

/**
 * node_address_compare2 - checks for a match between the address
 * held in ptrhold and the address passed as nextnode
 * @head: the start of the ptrhold list
 * @nextnode: the address to be checked for in ptrhold list
 * Return: 1 for a match, 0 for no match
 */
int node_address_compare2(ptrhold *head, listint_t *nextnode)
{
	while (head != NULL)
	{
		if (head->hold == (void *)nextnode)
		{
			return (1);
		}
		head = head->next;
	}
	return (0);
}

/**
 * free_listint_safe - frees a list with or without a loop, identifies
 * number loop elements
 * @h: a pointer to a pointer to the start of the list
 * Return: size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
	ptrhold *ptrListHead;
	listint_t *listintTmp;
	int count, loop;

	if (h == NULL)
		return (0);

	ptrListHead = NULL;
	count = 0;

	while (*h != NULL)
	{
		add_node2(&ptrListHead, *h);

		if (ptrListHead == NULL)
			return (count);

		listintTmp = (*h)->next;
		free(*h);
		count++;

		loop = node_address_compare2(ptrListHead, listintTmp);

		if (loop == 1)
		{
			free_ptrlist2(ptrListHead);
			*h = NULL;
			return (count);
		}
		*h = listintTmp;
	}
	free_ptrlist2(ptrListHead);

	return (count);
}

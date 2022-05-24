#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_ptrlist - frees a ptrhold list
 * @head: a pointer to the start of the list
 * Return: nothing.
 */
void free_ptrlist(ptrhold *head)
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
 * add_node - adds a new node at the beginning of a list
 * @head: a pointer to a pointer to the start of the list
 * @hold: the integer to be inserted in the new node
 * Return: address of the new element
 */
ptrhold *add_node(ptrhold **head, listint_t *hold)
{
	ptrhold *new;

	if (head == NULL)
		exit(98);

	new = malloc(sizeof(*new));

	if (new == NULL)
	{
		free_ptrlist(*head);
		exit(98);
	}

	new->hold = hold;
	new->next = *head;
	*head = new;

	return (*head);
}

/**
 * node_address_compare - checks for a match between the address
 * held in ptrhold and the address passed as nextnode
 * @head: the start of the ptrhold list
 * @nextnode: the address to be checked for in ptrhold list
 * Return: 1 for a match, 0 for no match
 */
int node_address_compare(ptrhold *head, listint_t *nextnode)
{
	while (head != NULL)
	{
		if (head->hold == (void *)nextnode)
		{
			printf("-> [%p] %d\n", (void *)nextnode, nextnode->n);
			return (1);
		}
		head = head->next;
	}
	return (0);
}

/**
 * print_listint_safe - prints a list with our without a loop, identifies loop
 * elements
 * @head: a pointer to the start of the list
 * Return: number of nodes in the list. Exit with 98 for failure
 */
size_t print_listint_safe(const listint_t *head)
{
	ptrhold *ptrListHead;
	listint_t *listintTmp;
	int count, loop;

	if (head == NULL)
		return (0);

	if (head->next == head)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		printf("-> [%p] %d\n", (void *)head, head->n);
		return (1);
	}

	ptrListHead = NULL;
	add_node(&ptrListHead, (listint_t *)head);
	if (ptrListHead == NULL)
		return (0);

	printf("[%p] %d\n", (void *)head, head->n);
	listintTmp = head->next;
	count = 1;

	while (listintTmp != NULL)
	{
		printf("[%p] %d\n", (void *)listintTmp, listintTmp->n);
		add_node(&ptrListHead, listintTmp);
		count++;
		loop = node_address_compare(ptrListHead, listintTmp->next);
		if (loop == 1)
		{
			free_ptrlist(ptrListHead);
			return (count);
		}
		listintTmp = listintTmp->next;
	}
	free_ptrlist(ptrListHead);
	return (count);
}

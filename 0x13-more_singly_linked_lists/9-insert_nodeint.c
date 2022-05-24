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

/**
 * get_nodeint_at_index - finds the address of the nth node
 * @head: pointer to the start
 * @index: index for the node to be returned (beginning at 0)
 * Return: pointer to the nth node
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count = 0;

	if (head == NULL)
		return (NULL);

	if (index == 0)
		return (head);

	while (count < index && head != NULL)
	{
		head = head->next;
		count++;
	}

	if (head == NULL)
		return (0);

	return (head);
}

/**
 * add_nodeint - adds a new node at the beginning of a list
 * @head: a pointer to a pointer to the start of the list
 * @n: the integer to be inserted in the new node
 * Return: address of the new element
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(*new));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}

/**
 * insert_nodeint_at_index - insert new node at nth node point
 * @head: pointer to pointer to start of the list
 * @idx: index to node position for new node
 * @n: the integer to be inserted in new node
 * Return: address to new node or NULL if failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *insert, *new, *temp;
	unsigned int listlen;

	if (head == NULL)
		return (NULL);

	if (idx == 0)
	{
		new = add_nodeint(head, n);
		if (new == NULL)
			return (NULL);
		new->n = n;
		return (new);
	}

	listlen = listint_len(*head);

	if (idx > listlen + 1)
		return (NULL);

	insert = get_nodeint_at_index(*head, idx);

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);

	new->n = n;

	temp = *head;
	while (temp->next != insert)
	{
		temp = temp->next;
	}
	temp->next = new;
	new->next = insert;

	return (new);
}

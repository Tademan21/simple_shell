#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - delete head node and return data
 * @head: pointer to tehfirst node
 * Return: data held at first node
 */
int pop_listint(listint_t **head)
{
	int hold;
	listint_t *newStart;

	if (*head == NULL)
		return (0);

	hold = (*head)->n;
	newStart = (*head)->next;
	free(*head);
	*head = newStart;

	return (hold);
}

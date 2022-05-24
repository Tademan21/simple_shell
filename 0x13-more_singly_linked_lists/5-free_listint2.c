#include <stdlib.h>
#include "lists.h"

/**
 * free_listint2 - frees a listint_t list and sets header ptr to NULL
 * @head: a pointer to a pointer to the start of the list
 * Return: nothing.
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL || *head == NULL)
		return;

	while (*head != NULL)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
	*head = NULL;
}

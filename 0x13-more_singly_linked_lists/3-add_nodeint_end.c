#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint_end - adds a new list_t element at the end
 * @head: a pointer to a pointer to the first node
 * @n: the integer to be held in the new node
 * Return: the address of the new node
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new, *hold;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(*new));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}
	else
	{
		hold = *head;
		while (hold != NULL)
		{
			if (hold->next == NULL)
			{
				hold->next = new;
				return (*head);
			}
			hold = hold->next;
		}
	}

	return (new);
}

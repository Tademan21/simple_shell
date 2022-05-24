#include <stdlib.h>
#include "lists.h"

/**
 * sum_listint - adds all the data in a listint_t
 * @head: pointer to the start of the list
 * Return: sum of all data in listint_t or 0 if list is empty
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	if (head == NULL)
		return (0);

	while (head != NULL)
	{
		sum = sum + head->n;
		head = head->next;
	}

	return (sum);
}

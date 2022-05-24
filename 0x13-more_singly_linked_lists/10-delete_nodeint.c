#include <stdlib.h>
#include "lists.h"

/**
 * get_nodeint_at_index - finds the address of the nth node
 * @head: pointer to the start
 * @index: index for the node to be returned (beginning at 0)
 * Return: pointer to the nth node
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count = 0;
	listint_t *temp;

	if (head == NULL)
		return (NULL);

	if (index == 0)
		return (head);

	temp = head;
	while (count < index && temp != NULL)
	{
		temp = temp->next;
		count++;
	}

	if (temp == NULL)
		return (0);

	return (temp);
}

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

/**
 * delete_nodeint_at_index - insert new node at nth node point
 * @head: pointer to pointer to start of the list
 * @idx: index to node position for deletion
 * Return: 1 for success, -1 for failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int idx)
{
	listint_t *del, *temp;
	int status;

	if (head == NULL)
		return (-1);

	if (idx == 0)
	{
		status = pop_listint(head);
		if (status == 0)
			return (-1);
		else
			return (1);
	}

	del = get_nodeint_at_index(*head, idx);

	if (del == NULL || del == 0)
		return (-1);

	temp = *head;
	while (temp->next != del)
	{
		temp = temp->next;
	}

	if (del->next == NULL)
	{
		temp->next = NULL;
		free(del);
		return (1);
	}

	temp->next = del->next;
	free(del);
	return (1);
}

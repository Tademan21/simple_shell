#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * _strlen - finds the length of a string
 * @s: the string to be examined
 * Return: the number of chars in the string as an int)
 */
int _strlen(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen(s + 1));
}

/**
 * add_node_end - adds a new node to the end of the list
 * @head: pointer to pointer to start of list
 * @str: string pointer for inclusion of string
 * Return: address of new element or NULL if failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *newEnd;
	list_t *last;

	if (head == NULL || str == NULL)
		return (NULL);

	newEnd = malloc(sizeof(list_t));
	if (newEnd == NULL)
		return (NULL);

	newEnd->str = strdup(str);
	if (newEnd->str == NULL)
	{
		free(newEnd);
		return (NULL);
	}

	newEnd->len = _strlen(newEnd->str);
	newEnd->next = NULL;

	if (*head == NULL)
	{
		*head = newEnd;
		return (newEnd);
	}

	last = *head;
	while (last->next != NULL)
		last = last->next;

	last->next = newEnd;

	return (newEnd);
}

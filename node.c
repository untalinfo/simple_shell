#include "holberton.h"

/**
 * add_node - add node to the list.
 * @str: string data
 * @head: head of list
 * Return: the list.
 */
list_t *add_node(list_t **head, char *str)
{
	list_t *add;

	add = malloc(sizeof(list_t));
	if (add == NULL)
		return (NULL);
	add->str = _strdup(str);
	add->next = *head;
	*head = add;

	return (add);
}

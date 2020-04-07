#include "holberton.h"

/**
 * add_node - add node to the list.
 * @str: string data
 * @head: head of list
 * Return: the list.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *add;

	add = malloc(sizeof(list_t));
	if (add == NULL)
		return (NULL);
	add->str = strdup(str);
	add->next = *head;
	*head = add;

	return (add);
}

/**
 * print_list - prints all the elements of a list_t list.
 * @h: the list
 * Return: # of elements.
 */
size_t print_list(const list_t *h)
{
	unsigned long n = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
		{
			printf("(nil)");
		}
		else
			printf("%s\n", h->str);
		h = h->next;
		n++;
	}
	return (n);
}

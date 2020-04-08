
#include "holberton.h"

void free_list(list_t *head)
{

list_t *temp, *buff;

	temp = head;
	while (temp != NULL)
	{
		buff = temp->next;
		free(temp->str);
		free(temp);
		temp = buff;

	}
}
void free_tok(char **token)
{
	int i;
	i = 0;
	while (token[i])
	{
		free(token[i]);
		i++;
	}
	free(token);
}

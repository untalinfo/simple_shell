
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
	head = NULL;
}


void free_tok(char **token)
{
	unsigned int i = 0;
	
	if (token == NULL)
		return;
	while (token[i])
	{
		free(token[i]);
		i++;
	}
	if (token[i] == NULL)
		free(token[i]);
	free(token);
}

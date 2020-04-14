#include "holberton.h"
/**
 * free_list - function that free the linkend list
 * @head: pointer to head of linkend list
 * Return: none
 */
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
/**
 * free_tok - function free the token
 * @token: double pointer to elements that were stored in the token
 * Return: none
 */
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

	free(token);
}
/**
 * free_exit - funtion send to free whent token is equals to exit
 * @_p: pointer to path
 * @d: Pointer to elements of getline
 * @h: pointer to head of linkend list
 * @token: double pointer to elements that were stored in the token
 * @cur: pointer to current directory
 * @er: pointer to stoered varible error
 * Return: none
 */
void free_exit(char *_p, char *d, list_t *h, char **token, char *cur, int *er)
{
	free(_p);
	free(d);
	free_list(h);
	free_tok(token);
	free(cur);
	exit(*er);
}

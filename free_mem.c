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
 * @_path: pointer to
 * @data: Pointer to
 * @head: pointer to head of linkend list
 * @token: double pointer to elements that were stored in the token
 * @cur: pointer to current directory
 * Return: none
 */
void free_exit(char *_path, char *data, list_t *head, char **token, char *cur)
{
	free(_path);
	free(data);
	free_list(head);
	free_tok(token);
	free(cur);
	exit(EXIT_SUCCESS);
}

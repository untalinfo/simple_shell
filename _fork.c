#include "holberton.h"
/**
 * _fork - after fork, this function call the function
 * @token: double pointer with the input commands and flags
 * @head: pointer to head of linkend list
 * Return: return 1 if fork is success
 */
int _fork(char **token, const list_t *head)
{

	int i = 0;
	struct stat st;

	if (stat(token[i], &st) == 0)
	{
		if (execve(token[0], token, NULL) == -1)
		{
			perror("Error: ");
			return (-1);
		}
	}
	else
		search_path(token, head);
	return (1);
}
/**
 * _fork_fail - function that print the erro when fork fail
 * Return: None
 */
void _fork_fail(void)
{
	perror("Error: ");
	exit(EXIT_FAILURE);
}

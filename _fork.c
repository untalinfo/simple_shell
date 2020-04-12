#include "holberton.h"
/**
 * _fork - after fork, this function call the function
 * @token: double pointer with the input commands and flags
 * @head: pointer to head of linkend list
 * Return: return 1 if fork is success
 */
int _fork(char **token, const list_t *head)
{

	//int i = 0;
	//struct stat st;
	pid_t hijo;
	int w = 0;

	hijo = fork();

	if (hijo < 0)
		_fork_fail();
	if (hijo == 0)
	{
		if (search_path(token, head) == -1)
		{
			//if (stat(token[i], &st) == 0)
			//{
				if (execve(token[0], token, NULL) == -1)
				{
					perror("Error: ");
					return (-1);
				}
			//}
		}
		write(1, token[0], _strlen(token[0]));
		write(1, ": command not found\n", 20);	
		exit(-1);
	}
	else
		wait(&w);
	return (EXIT_SUCCESS);
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

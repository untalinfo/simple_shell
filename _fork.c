#include "holberton.h"
/**
 * _fork - after fork, this function call the function
 * @token: double pointer with the input commands and flags
 * Return: FALTA
 */
int _fork(char **token)
{

	int i = 0;
	struct stat st;

	if (stat(token[i], &st) == 0)
	{
		if (execve(token[0], token, NULL) == -1)
		{
			perror("Error:");
			return (-1);
		}
	}
	else
		printf("%s: command not found\n", token[0]);
	return (1);
}

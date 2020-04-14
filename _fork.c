#include "holberton.h"
/**
 * _fork - after fork, this function call the function
 * @token: double pointer with the input commands and flags
 * @head: pointer to head of linkend list
 * @count: counter executed commands
 * @av: double pointer to aguments
 * @er: pointer to variable stored status error
 * Return: return 1 if fork is success
 */
int _fork(char **token, const list_t *head, int count, char **av,
 int *er, char **env)
{

	int i = 0;
	struct stat st;
	pid_t hijo;
	int w = 0;
	char msg[80];

	hijo = fork();

	if (hijo < 0)
		_fork_fail();
	if (hijo == 0)
	{
		if (search_path(token, head, env) == -1)
		{
			if (stat(token[i], &st) == 0)
			{
				if (execve(token[0], token, env) == -1)
				{
					sprintf(msg, "%s: cannot access '%s': No such file or directory \n",
						token[0], token[1]);
					write(STDERR_FILENO, &msg, _strlen(msg));
					exit(2);
				}
			}
		}
		sprintf(msg, "%s: %d: %s: not found\n", av[0], count, token[0]);
		write(STDERR_FILENO, &msg, _strlen(msg));
		exit(127);
	}
	else
	{
		wait(&w);
		if (WIFEXITED(w))
			*er = WEXITSTATUS(w);
	}
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

#include "holberton.h"
/**
 * _fork - after fork, this function call the function
 * @token: double pointer with the input commands and flags
 * @head: pointer to head of linkend list
 * @c: counter executed commands
 * @av: double pointer to aguments
 * @er: pointer to variable stored status error
 * @env: enviroment
 * @_path: the path
 * @data: getline string
 * @cur: previous directory
 * Return: return 1 if fork is success
 */
int _fork(char **token, list_t *head, int c, char **av,
int *er, char **env, char *_path, char *data, char *cur)
{
	struct stat st;
	pid_t hijo;
	int w = 0, i = 0;
	char msg[80];

	hijo = fork();
	if (hijo < 0)
		_fork_fail();
	if (hijo == 0)
	{
		if (search_path(token, head, env) == -1)
			if ((stat(token[i], &st) == 0) && token[i][0] == '/')
				execve(token[0], token, env);
		if (!_strcmp(token[0], "/bin") || !_strcmp(token[0], "/bin/") ||
		!_strcmp(token[0], "..") || !_strcmp(token[0], "/tmp"))
		{
			sprintf(msg, "%s: %d: %s: Permission denied\n", av[0], c, token[0]);
			write(STDERR_FILENO, &msg, _strlen(msg));
			free_tok(token), free_list(head), free(cur), free(data), free(_path);
			exit(126);
		}
		else if (!_strcmp(token[0], ".") && !_strcmp(token[1], "."))
			sprintf(msg, "%s: %d: %s: %s: not found\n", av[0], c, token[0], token[1]);
		else
			sprintf(msg, "%s: %d: %s: not found\n", av[0], c, token[0]);
		write(STDERR_FILENO, &msg, _strlen(msg));
		free_tok(token), free_list(head), free(cur), free(data), free(_path);
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

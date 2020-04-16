#include "holberton.h"
/**
 * _cd - function that allows to change directory
 * @token: pointer to commands from tok
 * @current: pointer to current directory
 * @env: enviroment
 * @av: argv pointer
 * @c: instrunction counter
 * @er: error pointer
 * Return: current
 */
char *_cd(char **token, char *current, char **env, char **av, int c, int *er)
{
	char *buff = NULL, *home = NULL;
	char msg[100];

	buff = malloc(200);
	if (buff == NULL)
		return (NULL);
	getcwd(buff, 200);

	if (token[1] == NULL || (!_strcmp(token[1], "~")))
	{
		home = _getenv("HOME", env);
		chdir(home);
		getcwd(current, 200);
	}
	else if (_strcmp(token[1], "-") == 0)
	{
		write(1, current, _strlen(current));
		write(1, "\n", 1);
		chdir(current);
	}
	else
	{
		if (chdir(token[1]) == -1)
		{
			sprintf(msg, "%s: %d: %s: can't cd to %s\n", av[0], c, token[0], token[1]);
			write(STDERR_FILENO, &msg, _strlen(msg));
			*er = 2;
		}
	}
	_strcpy(current, buff);
	free(buff);
	free(home);
	return (current);
}

#include "holberton.h"
/**
 * _cd - function that allows to change directory
 * @token: pointer to commands from tok
 * @current: pointer to current directory
 * @env: enviroment
 * Return: current
 */
char *_cd(char **token, char *current, char **env)
{
	char *buff = NULL, *home = NULL;

	buff = malloc(200);
	if (buff == NULL)
		return (NULL);
	getcwd(buff, 200);

	if (token[1] == NULL)
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
		chdir(token[1]);
	}
	_strcpy(current, buff);
	free(buff);
	free(home);
	return (current);
}

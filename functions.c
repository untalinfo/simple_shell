#include "holberton.h"
/**
 * _cd - function that allows to change directory
 * @token: pointer to commands from tok
 * @current: pointer to current directory
 * Return: current
 */
char *_cd(char **token, char *current)
{
	/*size_t len = PATH_MAX;*/
	char *buff = NULL;

	buff = malloc(PATH_MAX);
	/*getcwd(p, len);*/
	if (buff == NULL)
		return (NULL);
	getcwd(buff, PATH_MAX);

	if (token[1] == NULL)
	{
		chdir("/home");
		getcwd(current, PATH_MAX);
		/*mod_pwd(current);*/
	}
	else if (_strcmp(token[1], "-") == 0)
	{
		write(1, current, _strlen(current));
		write(1, "\n", 1);
		chdir(current);
		/*mod_pwd(current);*/
	}
	else
	{
		chdir(token[1]);
	}
	_strcpy(current, buff);
	free(buff);
	return (current);
}

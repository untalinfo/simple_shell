#include "holberton.h"
/**
 * _getenv - function to get the eviroment variable
 * @str: string of the enviroment variables
 * Return: The value of variable
 */
char *_getenv(char *str)
{
	int i;
	char *path;

	for (i = 0; environ[i] != NULL; i++)
	{
		if ((environ[i][0] == str[0]) && (environ[i][1] == str[1])
			&& (environ[i][2] == str[2]) && (environ[i][3] == str[3]))
		{
			path = malloc(_strlen(environ[i]) - _strlen(str));
			_strcpy(path, _strchr(environ[i], '/'));
		}
	}
	return (path);
}

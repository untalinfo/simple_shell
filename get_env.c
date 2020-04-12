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
			if (_strlen(environ[i]) > 5)
			{	
				path = malloc(_strlen(environ[i]) - _strlen(str));
				if (path == NULL)
					return (NULL);
				_strcpy(path, _strchr(environ[i], '/'));
			}
			else
			{
				path = NULL;
			}
			
		}
	}
	return (path);
}

/**
 * print_env - function print the enviroment
 */
void print_env(void)
{
	unsigned int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

void mod_pwd(char *str)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if ((environ[i][0] == 'P') && (environ[i][1] == 'W')
			&& (environ[i][2] == 'D'))
		{
			//path = malloc(_strlen(environ[i]) - _strlen(str));
			//if (path == NULL)
			//	return (NULL);
			_strcpy(_strchr(environ[i], '/'),str);
		}
	}
}

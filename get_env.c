#include "holberton.h"
/**
 * _getenv - function to get the eviroment variable
 * @str: string PATH
 * Return: The value of variable
 * @env: enviroment
 */
char *_getenv(char *str, char **env)
{
	int i;
	char *path;

	for (i = 0; env[i] != NULL; i++)
	{
		if ((env[i][0] == str[0]) && (env[i][1] == str[1])
			&& (env[i][2] == str[2]) && (env[i][3] == str[3]))
		{
			if (_strlen(env[i]) > 5 && (env[i][5] != ':'))
			{
				path = malloc(_strlen(env[i]) - _strlen(str));
				if (path == NULL)
					return (NULL);
				_strcpy(path, _strchr(env[i], '/'));
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
 * @env: enviroment
 * Return: None
 */
void print_env(char **env)
{
	unsigned int i = 0;

	while (env[i])
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * mod_pwd - function that modify pwd in the environ variable
 * @str: pointer to current directory
 * @env: enviroment
 * Return: none
 */
void mod_pwd(char *str, char **env)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		if ((env[i][0] == 'P') && (env[i][1] == 'W')
			&& (env[i][2] == 'D'))
		{
			_strcpy(_strchr(env[i], '/'), str);
		}
	}
}

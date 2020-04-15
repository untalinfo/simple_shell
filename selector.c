#include "holberton.h"
/**
 * search_path - verify the command in the path, return the binary address
 * @token: commands splited in array
 * @h: head of the path linked list
 * @env: enviroment
 * Return: -1 if path not found
 */
int search_path(char **token, const list_t *h, char **env)
{
	char *bin_com = NULL;
	struct stat st;
	char msg[80];

	while (h != NULL)
	{
		bin_com = malloc(_strlen(token[0]) + _strlen(h->str) + 2);
		_strcpy(bin_com, h->str);
		_strncat(bin_com, "/", 1);
		_strncat(bin_com, token[0], _strlen(token[0]));

		if (stat(bin_com, &st) == 0)
		{
			if (execve(bin_com, token, env) == -1)
			{
				sprintf(msg, "%s: cannot access '%s': No such file or directory \n",
					token[0], token[1]);
				write(STDERR_FILENO, &msg, _strlen(msg));
				exit(2);
			}
		}
		h = h->next;
		free(bin_com);
		bin_com = NULL;
	}
	return (-1);
}

/**
 * _divisor - split the path and store it in linked list
 * @_path: the path
 * @head: head of the path linked list
 * Return: 0 if success
 */

int _divisor(char *_path, list_t **head)
{
	char *str;
	char *tmppath = NULL;

	tmppath = malloc(_strlen(_path) + 1);
	if (tmppath == NULL)
		return (-1);
	_strcpy(tmppath, _path);
	str = strtok(tmppath, ":");
	while (str != NULL)
	{
		add_node(head, str);
		str = strtok(NULL, ":");
	}
	free(tmppath);
	return (0);
}

/**
 * com_split - split the input commands and flags and
 * store it in double pointer
 * @commands: command input from getline
 * Return: the double pointer with commands
 */

char **com_split(char *commands)
{
	char **token = NULL;
	char *tok = NULL;
	int len = 0;
	char *temp;
	char *temp2;
	int i = 0;

	temp2 = malloc(sizeof(char) * _strlen(commands) + 1);
	if (temp2 == NULL)
		return (NULL);
	_strcpy(temp2, commands);
	tok = strtok(commands, " ");
	if (*tok == '\n' || *tok == '.' || *tok == '\t' || *tok == '\r' ||
	*tok == '\a')
	{
		free(temp2);
		return (NULL);
	}
	while (tok)
		len++, tok = strtok(NULL, " ");
	token = malloc(sizeof(char *) * (len + 1));
	if (token == NULL)
		return (NULL);
	temp = strtok(temp2, " \n\t\r\a");
	i = 0;
	while (temp != NULL)
	{
		token[i] = _strdup(temp);
		if (token[i] == NULL)
		{	/*FREE TOKEN*/
			free_tok(token);
			return (NULL);
		}
		_strcpy(token[i], temp);
		temp = strtok(NULL, " \n\t\r\a");
		i++;
	}
	token[i] = NULL;
	free(temp2);
	return (token);
}

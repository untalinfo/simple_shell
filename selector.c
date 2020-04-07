#include "holberton.h"
/**
 * search_path - verify the command in the path, return the binary address
 * @command: command input
 * @h: head of the path linked list
 */

void search_path(char *command, const list_t *h)
{

char *bin_com = NULL;
char *temp = NULL;
bin_com = malloc(sizeof(char));
temp = malloc(sizeof(char));

struct stat st;
	while (h != NULL)
	{
		strcpy(bin_com, command);
		bin_com = realloc(bin_com, _strlen(command) + _strlen(h->str) + 1);
		temp = realloc(temp, sizeof(char) * _strlen(h->str) + 1);
		strcpy(temp, h->str);
		bin_com = strncat(temp, "/", 1);
		bin_com = strncat(bin_com, command, strlen(command));
		if (stat(bin_com, &st) == 0)
		{
			command = realloc(command, _strlen(bin_com));
			strcpy(command, bin_com);
			free(bin_com);
			break;
		}
		h = h->next;
	}
}

/**
 * _divisor - split the path and store it in linked list
 * @_path: the path
 * @head: head of the path linked list
 * Return: FALTA
 */

int _divisor(char *_path, list_t **head)
{
	char *str;

	str = strtok(_path, ":");
		while (str != NULL)
		{
			add_node(head, str);
			str = strtok(NULL, ":");
		}
	return (0);
}

/**
 * com_split - split the input commands and flags and
 * store it in double pointer
 * @commands: command input
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

	temp2 = malloc(sizeof(char) * strlen(commands));
	strcpy(temp2, commands);
	tok = strtok(commands, " ");
	while (tok)
	{
		len++;
		tok = strtok(NULL, " ");
	}
	token = malloc(sizeof(char *) * len + 1);
	temp = strtok(temp2, " \n");

	for (i = 0; i < len; i++)
	{
		token[i] = malloc(sizeof(char *) * strlen(temp));
		strcpy(token[i], temp);
		temp = strtok(NULL, " \n");
	}
	return (token);
}


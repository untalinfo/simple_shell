#include "holberton.h"

/////////////////divide el path y guarda cada direccion en nodo de una linked list
int _divisor(char *_path, list_t **head)
{
	char *str;
	
	str = strtok(_path,":");
	

		while (str != NULL)
		{
			add_node(head, str);
			str = strtok(NULL,":");
		}
	return (0);
}


//////divide los comandos y los guarda en un puntero doble//////////////
char **com_split(char *commands)
{
	char **token = NULL;
	char *tok = NULL;
	int len=0;
	char *temp;
	char *temp2;
	int i = 0;
	
	temp2=malloc(sizeof(char)*strlen(commands));
	strcpy(temp2,commands);

	tok = strtok(commands, " ");
	
	while (tok)
	{
		len++;
		tok = strtok(NULL, " ");
	}
	token = malloc(sizeof(char *) * len + 1);
	temp = strtok(temp2," \n");
		
	for (i = 0; i < len; i++)
	{
		token[i] = malloc(sizeof(char *) * strlen(temp));
		strcpy(token[i], temp);
		temp = strtok(NULL," \n");
	}
	return (token);
}


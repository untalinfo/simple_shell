#include "holberton.h"


char *_getenv(char *str)
{
	
	int i;
	char *path; 
	
	
	for (i = 0; environ[i] != NULL; i++)
	{
		if ((environ[i][0] == 'P') && (environ[i][1] == 'A') && (environ[i][2] == 'T') && (environ[i][3] == 'H'))
		{
			path = malloc(_strlen(environ[i])-4);
			_strcpy(path,_strchr(environ[i],'/'));
		}
	}
	return (path);
}
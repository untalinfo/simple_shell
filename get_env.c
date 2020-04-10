#include "holberton.h"


char *get_env(void)
{
	char *path = "PATH";
	int i;
	path = path;
	for (i = 0; environ[i] != NULL; i++)
	{
		
		printf("%s\n",environ[i]);
	}


	/*char *four = malloc(4);
	int compare;
	
	for (i = 0; environ[i] != NULL; i++)
	{
		four[0] = environ[i][0];
		four[1] = environ[i][1];
		four[2] = environ[i][2];
		four[3] = environ[i][3];
		compare = _strcmp(four, path);
		//printf("%d\n",_strlen(environ[i]));
		//printf("%s\n",environ[i]);
		if (compare == 0)
		{
			path = malloc(_strlen(environ[i]));
			_strcpy(path, environ[i]);
			printf("%s\n",path);
		}
			
			
	}*/
	return (path);
}
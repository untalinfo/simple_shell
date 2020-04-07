#include "holberton.h"
/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	list_t *head = NULL;
	char *data = NULL;
    ssize_t rd;
    int w=0;
    pid_t hijo;
	char * _path;
	size_t len = 0;
	char **token = NULL;
	_path = getenv("PATH");
	char *ex = "exit\n";
	
	_divisor(_path, &head);
    do
    {
		write(1,"$ ",2);
		rd = getline(&data, &len, stdin);
		if (strcmp(ex, data) == 0)
			exit(-1);

		token = com_split(data);
		search_path(token[0], head);

		hijo=fork();

		if (hijo == 0)
			_fork(token);	
		else
			wait(&w);
	}while (rd != -1);
    return (0);
}



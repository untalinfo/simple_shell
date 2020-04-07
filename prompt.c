#include "holberton.h"

/**
 * ctrlC - function that handles signal and write the prompt
 * @sig: signal to handler
 * Return: None
 */
void ctrlC(int sig)
{
	(void) sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}
/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{

	char *data = NULL;
  ssize_t rd;
  int w=0;
	list_t *head;
	head = NULL;
	int i=0;
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

		signal(SIGINT, ctrlC);

		if(rd == EOF)
			end_of_file(data);
		
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
	if (rd == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}



#include "holberton.h"

/**
 * main -  principal function to run the programm
 *
 * Return: Always 0.
 */
int main(void)
{

	char *data = NULL;
	ssize_t rd;
	int w = 0;
	pid_t hijo;
	list_t *head;
	char *_path;
	size_t len = 0;
	char **token = NULL;
	char *ex = "exit\n";

	head = NULL;
	_path = getenv("PATH");
	_divisor(_path, &head);
	do {
		print_prompt();
		rd = getline(&data, &len, stdin);
		if(*data != '\n')
		{
		signal(SIGINT, ctrlC);

		if (rd == EOF)
			end_of_file(data);

		if (strcmp(ex, data) == 0)
			exit(-1);

		token = com_split(data);
		search_path(token[0], head);

		hijo = fork();
		if (hijo == 0)
			_fork(token);
		else
			wait(&w);
		data = NULL, len = 0;
		}
	} while (rd != -1);
	if (rd == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

#include "holberton.h"
/**
 * main -  principal function to run the programm
 *
 * Return: Always 0.
 */
int main(void)
{

	char *data = NULL, *_path;
	ssize_t rd;
	int w = 0;
	pid_t hijo;
	list_t *head;
	size_t len = 0;
	char **token = NULL;

	head = NULL, _path = _getenv("PATH");
	_divisor(_path, &head);
	/*print_list(head);*/
	do {
		print_prompt();
		signal(SIGINT, ctrlC);
		rd = getline(&data, &len, stdin);
		if (*data != '\n')
		{
			if (rd == EOF)
				end_of_file(data);

			token = com_split(data);

			if (_strcmp("exit", token[0]) == 0)
			{
				free_exit(_path, data, head, token);
				exit(-1);
			}

			hijo = fork();
			if (hijo < 0)
				_fork_fail();
			if (hijo == 0)
			{
				_fork(token, head);
				exit(-1);
			}
			else
				wait(&w);

			free_tok(token);
			free(data);
			data = NULL, len = 0;
		}
	} while (rd != -1);
	if (rd == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

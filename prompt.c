#include "holberton.h"
/**
 * main -  main function to run the programm
 *
 * Return: Always 0.
 */
int main(void)
{
	char *current = NULL;
	char *data = NULL, *_path;
	ssize_t rd;
	list_t *head;
	size_t len = 0;
	char **token = NULL;

	current = malloc (PATH_MAX);
	
	
	do {
		head = NULL; 
		_path = _getenv("PATH");
		if (_path != NULL)
			_divisor(_path, &head);
		
		print_prompt();
		signal(SIGINT, ctrlC);
		rd = getline(&data, &len, stdin);
		if (*data != '\n')
		{
			if (rd == EOF)
				end_of_file(data);

			token = com_split(data);
			if (token == NULL)
				continue;
			if (_strcmp("exit", token[0]) == 0)
				free_exit(_path, data, head, token, current), exit(EXIT_SUCCESS);
			else if (_strcmp("env", token[0]) == 0)
				print_env();
			else if (_strcmp("cd", token[0]) == 0)
				current = _cd(token, current);
			else if (_strcmp("$PATH", token[0]) == 0)
				write(1,_path,strlen(_path));
			else
				_fork(token, head);
			free_tok(token), free(data), free(_path), free_list(head);
			data = NULL, len = 0;
		}
	} while (rd != -1);
	if (rd == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

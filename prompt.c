#include "holberton.h"
/**
 * main -  main function to run the programm
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	char *current = NULL;
	char *data = NULL, *_path;
	ssize_t rd;
	list_t *head;
	size_t len = 0;
	char **token = NULL;
	int count=0;
	
	(void) ac;
	current = malloc(PATH_MAX);
	if (current == NULL)
		return (12);/* pendiente validacion de error*/
	do {
		head = NULL;
		_path = _getenv("PATH");
		if (_path != NULL)
			if (_divisor(_path, &head) == -1)/*por verificar*/
			{
				free(_path), perror("Error: ");
				continue;
			}
		print_prompt();
		signal(SIGINT, ctrlC);
		rd = getline(&data, &len, stdin);
		count++;
		if (*data != '\n')
		{
			if (rd == EOF)
				end_of_file(data);
			token = com_split(data);
			if (token == NULL)
			{
				perror("Error: ");
				continue;/*pendiente*/
			}
			exec(token,  current, _path, head, data, count, av);
			free_tok(token), free(data), free(_path), free_list(head);
			data = NULL, len = 0;
		}
	} while (rd != -1);
	if (rd == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * exec - function that execute divers proccesses
 * @token: double pointer whit commmands
 * @current: pointer of the previus  directory
 * @_path: store the enviroment variable: path
 * @head: pointer to firts element of linkend list
 * @data: pointer to elements of getline
 * Return: None
 */
void exec(char **token, char *current, char *_path, list_t *head, char *data, int c, char **av)
{
	if (_strcmp("exit", token[0]) == 0)
		free_exit(_path, data, head, token, current), exit(EXIT_SUCCESS);
	else if (_strcmp("env", token[0]) == 0)
		print_env();
	else if (_strcmp("cd", token[0]) == 0)
		current = _cd(token, current);
	else if (_strcmp("$PATH", token[0]) == 0)
		write(1, _path, strlen(_path));
	else
		_fork(token, head, c, av);
}

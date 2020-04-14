#include "holberton.h"
/**
 * main -  main function to run the programm
 * @ac: number elements of av
 * @av: double pointer to arguments
 * @env: enviroment
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	char *data = NULL, *_path, *current = NULL, **token = NULL;
	ssize_t rd;
	list_t *head = NULL;
	size_t len = 0;
	int count = 0, error = 0, *er = &error;

	current = malloc(200);
	if (current == NULL)
		exit(12);/* pendiente validacion de error*/
	if (ac > 1)
		exit(EXIT_SUCCESS);
	print_prompt();
	while ((rd = getline(&data, &len, stdin)))
	{
		_path = _getenv("PATH", env);
		if (_path != NULL)
			if (_divisor(_path, &head) == -1)/*por verificar*/
			{
				free(_path), perror("Error: ");
					continue;
			}
		signal(SIGINT, ctrlC), count++;
		if (*data != '\n')
		{
			if (rd == EOF)
				end_of_file(data, er);
			token = com_split(data);
			if (token == NULL)
			{
				perror("Error: ");
				continue;/*pendiente*/
			}
			exec(token,  current, _path, head, data, count, av, er, env);
			free_tok(token), free(data), free(_path), free_list(head);
			data = NULL, len = 0, print_prompt(), head = NULL;
		}
	}
	if (rd == -1)
		exit(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * exec - function that execute divers proccesses
 * @token: double pointer whit commmands
 * @current: pointer of the previus  directory
 * @_path: store the enviroment variable: path
 * @head: pointer to firts element of linkend list
 * @data: pointer to elements of getline
 * @c: counter to commands executed
 * @av: double pointer to arguments
 * @er: double pointer to variable status error
 * @env: enviroment
 * Return: None
 */
void exec(char **token, char *current, char *_path, list_t *head,
		char *data, int c, char **av, int *er, char **env)
{
	if (_strcmp("exit", token[0]) == 0)
		free_exit(_path, data, head, token, current, er);
	else if (_strcmp("env", token[0]) == 0)
		print_env(env);
	else if (_strcmp("cd", token[0]) == 0)
		current = _cd(token, current);
	else if (_strcmp("$PATH", token[0]) == 0)
		write(1, _path, _strlen(_path));
	else
		_fork(token, head, c, av, er, env);
}

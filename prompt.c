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
	char *data = NULL, *_path, *cur = NULL, **token = NULL;
	ssize_t rd;
	list_t *head = NULL;
	size_t len = 0;
	int count = 0, error = 0, *er = &error;

	cur = malloc(200);
	if (cur == NULL)
		exit(12);/* pendiente validacion de error*/
	if (ac > 1)
		exit(EXIT_SUCCESS);
	print_prompt();
	signal(SIGINT, ctrlC);
	while ((rd = getline(&data, &len, stdin)))
	{count++;
		if (rd == EOF)
			end_of_file(data, er, cur);
		_path = _getenv("PATH", env);
		if (_path != NULL)
			if (_divisor(_path, &head) == -1)/*por verificar*/
			{
				free(_path), perror("Error: ");
				continue;
			}
		if (*data != '\n')
		{
			token = com_split(data);
			if (token != NULL)
				exec(token,  cur, _path, head, data, count, av, er, env), free_tok(token);
		}
		free(data), free(_path), free_list(head);
		data = NULL, len = 0, head = NULL, print_prompt();
	}
	if (rd == -1)
		return (EXIT_FAILURE);
	return (*er);
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
int exec(char **token, char *current, char *_path, list_t *head,
		char *data, int c, char **av, int *er, char **env)
{
	char msg[180];

	if ((_strcmp("exit", token[0]) == 0) && (token[1] == NULL))
		free_exit(_path, data, head, token, current, er);
	if ((_strcmp("exit", token[0]) == 0) && (token[1] != NULL))
		*er = _atoi(token[1]), free_exit(_path, data, head, token, current, er);
	else if (_strcmp("env", token[0]) == 0 && token[1] == NULL)
		print_env(env);
	else if (_strcmp("cd", token[0]) == 0)
		current = _cd(token, current, env, av, c, er);
	else if (_strcmp("$PATH", token[0]) == 0)
	{
		sprintf(msg, "%s: %d: %s: not found\n", av[0], c, _path);
		write(STDERR_FILENO, &msg, _strlen(msg));
	}
	else if (_strcmp("help", token[0]) == 0 && token[1] == NULL)
		_hbuild(NULL);
	else if (_strcmp("help", token[0]) == 0)
	{
		if (_strcmp("help", token[1]) == 0)
			_hhelp();
		else if (_strcmp("cd", token[1]) == 0)
			_hcd();
		else if (_strcmp("exit", token[1]) == 0)
			_hlpexit();
		else if (_strcmp("-sd", token[1]) == 0)
			_hbuild(NULL);
		else
		{
			sprintf(msg, "%s: %d: help: no help topics match '%s'. Try ",
					av[0], c, token[1]);
			sprintf(msg, "%s'help help' or 'man -k %s' or 'info %s'.\n", msg,
					token[1], token[1]);
			write(STDERR_FILENO, msg, _strlen(msg));
		}
	}
	else
		_fork(token, head, c, av, er, env, _path, data, current);

	return (0);
}

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
	list_t *head;
	head = NULL;
	char *data;
    ssize_t rd;
	int i=0;
	pid_t hijo;
	int w;
    struct stat st;
	char * _path;
	size_t len = 0;
	char **token = NULL;
	_path = getenv("PATH");
	

	data = NULL;
		
char *ex = "exit\n";
    do
    {
		write(1,"$ ",2);
		rd = getline(&data, &len, stdin);

		signal(SIGINT, ctrlC);

		if(rd == EOF)
			end_of_file(data);
		
		if (strcmp(ex, data) == 0)
			exit(-1);
			
		//***********************************************
		token = com_split(data);
		_divisor(_path, &head);
		//print_list(head);
		//***********************************************
		
		i=0;
		/*
		while (token [i])
		{
			printf("%s\n", token[i]);
			i++;
		}
		*/
		hijo=fork();
		
		i=0;
		if (hijo == 0)
		{

			if (stat(token[i], &st) == 0)
			{
				
				if (execve(token[0], token, NULL) == -1)
				{
					perror("Error:");
					return (1);
				}
			}
			else
			{
				printf("%s: command not found\n", token[0]);
			}
		}
		else
		wait(&w);
	}while (rd != -1);
	if (rd == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}



#include "holberton.h"
/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(int argc, char **argv, char **env)
{
	list_t *head;
	head = NULL;
	char *data = NULL;
    ssize_t rd;
    char *p ;
	int i=0;
    p= "$ ";
	pid_t hijo;
	int w;
    struct stat st;
	char * _path;
	size_t len = 0;
	char **token = NULL;
	_path = getenv("PATH");
	
	argc = argc;
	argv = argv;
	env = env;

		
char *ex = "exit\n";
    do
    {
		write(1,p,2);
		rd = getline(&data, &len, stdin);
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
    return (0);
}



#include "holberton.h"

/**
 * _hlpexit - function help
 * Return: EXIT_SUCCESS in success.
 */
int _hlpexit(void)
{
int i; /* Line printing counter */
char *msg[] = {
"exit: exit [n]\n",
"    Exit the shell.\n",
"\n",
"    Exits the shell with a status of N.  If N is omitted, the exit status\n",
"    is that of the last command executed.\n",
NULL
};

	for (i = 0; msg[i] != NULL; i++)
		write(STDOUT_FILENO, msg[i], _strlen(msg[i]));

	return (EXIT_SUCCESS);
}

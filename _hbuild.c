#include "holberton.h"
/**
 * _hbuild - Print the build
 * @command: the command to print
 * Return: -19 in exit case, 1 in success, 0 in no exec
 */
int _hbuild(char *command)
{
int i; /* Line printing counter */
char *msg[] = {
"GNU hsh, version 1.0+ - release (x86_64-pc-linux-gnu)\n",
"These shell commands are defined internally.  Type 'help' to see this list.\n",
"Type 'help name' to find out more about the function 'name'.\n",
"Use 'info bash' to find out more about the shell in general.\n",
"Use 'man -k' or `info' to find out more about commands not in this list.\n",
"\n",
"A star (*) next to a name means that the command is disabled.\n",
"\n",
"cd [-L|[-P [-e]] [-@]] [dir]\n",
"exit [n]\n",
"help [-dms] [pattern ...]\n",
NULL
};

	if (command == NULL)
		for (i = 0; msg[i] != NULL; i++)
			write(STDOUT_FILENO, msg[i], _strlen(msg[i]));

	return (EXIT_SUCCESS);
}

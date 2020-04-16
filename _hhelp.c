#include "holberton.h"



/**
 * _hhelp - function help
 * Return: EXITSUCCESS in success.
 */
int _hhelp(void)
{
int i; /* Line printing counter */
char *msg[] = {
"help: help [-dms] [pattern ...]\n",
"    Display information about builtin commands.\n",
"\n",
"    Displays brief summaries of builtin commands.  If PATTERN is\n",
"    specified, gives detailed help on all commands matching PATTERN,\n",
"    otherwise the list of help topics is printed.\n",
"\n",
"    Options:\n",
"      -d        output short description for each topic\n",
"      -m        display usage in pseudo-manpage format\n",
"      -s        output only a short usage synopsis for each topic matching\n",
"        PATTERN\n",
"\n",
"    Arguments:\n",
"      PATTERN   Pattern specifiying a help topic\n",
"\n",
"    Exit Status:\n",
"    Returns success unless PATTERN is not found or an invalid option is given.\n",
NULL
};

	for (i = 0; msg[i] != NULL; i++)
		write(STDOUT_FILENO, msg[i], _strlen(msg[i]));

	return (EXIT_SUCCESS);
}

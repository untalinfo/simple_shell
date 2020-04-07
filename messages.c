#include "holberton.h"

/**
 * end_of_file - function that deteted EOF and exit the process
 * data: data of getline
 * Return: none
 */
void end_of_file(char *data)
{

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(data);
	exit(0);
}

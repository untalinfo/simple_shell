#include "holberton.h"

/**
 * print_prompt - function that prints the prompt
 *
 * Return: None
 */
void print_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "($) ", 4);
}
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
 * end_of_file - function that deteted EOF and exit the process
 * @data: data of getline
 * @er: pointer to variable stored status error
 * @current: previus directory
 * Return: none
 */
void end_of_file(char *data, int *er, char *current)
{

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(data);
	free(current);
	exit(*er);
}

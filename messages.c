#include "holberton.h"

void end_of_file(char *data)
{

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
//	free(data);
	exit(0);
}

#include "holberton.h"
/**
 * _strlen - returns the length of a string
 * @s: char array pointer
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _strlen(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}


/**
 * *_strncat - concatenate strings
 * @dest: array
 * @src: array
 * @n: numers os bytes to concatenate
 * Return: Always 0.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; j < n && src[j] != '\0'; j++)
		dest[i + j] = src[j];
	dest[i + j] = '\0';

	return (dest);
}

/**
 * *_strcpy - reverses a string
 * @dest: char array destiny
 * @src: array in
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

char *_strcpy(char *dest, char *src)
{
int i = 0;


	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (src);
}

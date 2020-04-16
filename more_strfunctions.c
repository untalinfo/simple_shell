#include "holberton.h"
/**
 * *_strchr - find and cut
 * @s: array in
 * @c: char to search
 * Return: Always 0.
 */

char *_strchr(char *s, char c)
{
	int j = 0;

	while (2)
	{
		if (s[j] == c)
			return (s + j);
		if (s[j] == '\0')
			return (NULL);
		j++;
	}
}

/**
 * _atoi - converts string to number
 * @s : pointer int
 *
 * _atoi: converts string to number
 *
 * Return: int
 */
int _atoi(char *s)
{
	int i;
	int check_num;
	unsigned int sum;
	unsigned int x;
	int neg;

	neg = 0;
	check_num = 0;
	sum = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] > '9' || s[i] < '0') && check_num > 0)
			break;
		if (s[i] == '-')
			neg++;
		if (s[i] >= '0' && s[i] <= '9')
			check_num++;
		i++;
	}
	i = i - 1;
	x = 1;
	while (check_num > 0)
	{
		sum = sum + ((s[i] - '0') * x);
		x = x * 10;
		i--;
		check_num--;
	}
	if (neg % 2 != 0)
		sum = sum * -1;
	return (sum);
}

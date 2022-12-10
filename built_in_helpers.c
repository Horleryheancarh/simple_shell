#include "main.h"

/**
 *countArgs - count number of args
 *@args: array of strings
 *
 *Return: number
 */
int countArgs(char **args)
{
	register int i = 0;

	while (args[i])
		i++;

	return (i);
}

/**
 *_atoi - change string to integer
 *@s: string
 *
 *Return: converted number or error
 */
int _atoi(char *s)
{
	register int i = 0;
	unsigned long num = 0;

	while (s[i])
	{
		if (s[i] > '0' && s[i] <= '9')
			num = num * 10 + s[i] - '0';
		else
			return (-1);

		i++;
	}

	if (num > INT_MAX)
		return (-1);

	return (num);
}

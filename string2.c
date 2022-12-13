#include "main.h"

/**
 *_strtok - tokenizes strings
 *@s: string
 *@d: delimiter
 *
 *Return: pointer to start of string
 */
char *_strtok(char *s, char *d)
{
	static char *p;
	char c;

	if (s == NULL)
		s = p;

	do {
		c = *s++;
		if (!c)
			return (NULL);
	} while (_strchr(d, c));

	s--;
	p = s + _strcspn(s, d);

	if (*p)
		*p++ = 0;

	return (s);
}

/**
 *_strcspn - returns first 
 *@str: string
 *@ch: char
 *
 *Return: pointer
 */
int _strcspn(char *str, char *ch)
{
	char c, *p, *s;

	for (s = str, c = *s; c; s++, c = *s)
		for (p = ch; *p; p++)
			if (c == *p)
				return (s - str);

	return (s - str);
}

/**
 *_strchr - locates a char in a str
 *@s: string
 *@c: char
 *
 *Return: pointer
 */
char *_strchr(char *s, char c)
{
	char x;

	while (true)
	{
		x = *s++;
		if (x == c)
			return (s - 1);
		if (!x)
			return (NULL);
	}
}

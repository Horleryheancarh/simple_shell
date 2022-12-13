#include "main.h"

/**
 *splitString - split sting into an array
 *@build: input field
 *
 *Return: true or false
 */
_Bool splitString(config *build)
{
	register unsigned int i = 0;
	char *tok, *copy;

	if (countWoord(build->buffer) == 0)
	{
		build->args = NULL;
		free(build->buffer);
		return (false);
	}

	build->args = malloc((countWords(build->buffer) + 1) * sizeof(char *));
	cpy = _strdup(build->buffer);
	tok = _strtok(cpy, " ");

	while (tok)
	{
		build->args[i] = _strdup(tok);
		tok = _strtok(NULL, " ");
		i++;
	}

	build->args[i] = NULL;
	free(cpy);
	return (true);
}

/**
 *countWords - count number of words in a string
 *@str: input string
 *
 *Return: integer
 */
unsigned int countWords(char *s)
{
	register int words = 0;
	_Bool wordOn = false;

	while (*s)
	{
		if (isSpace(*s) && wordOn)
			wordOn = false;
		else if (!isSpace(*s) && !wordOn)
		{
			wordOn = true;
			words++;
		}
		s++;
	}

	return (words);
}

/**
 *isSpace - determines if char is a space
 *@c: input char
 *
 *Return: true or false
 */
_Bool isSpace(char c)
{
	return (c == ' ');
}

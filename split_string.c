#include "main.h"

/**
 *splitString - split sting into an array
 *@build: input field
 *
 *Return: 1 on success or 0 on failure
 */
int splitString(config *build)
{
	register unsigned int i = 0;
	char *tok, *cpy;

	if (countWords(build->buffer) == 0)
	{
		build->args = NULL;
		free(build->buffer);
		return (0);
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
	return (1);
}

/**
 *countWords - count number of words in a string
 *@s: input string
 *
 *Return: integer
 */
unsigned int countWords(char *s)
{
	register int words = 0;
	int wordOn = 0;

	while (*s)
	{
		if (isSpace(*s) && wordOn)
			wordOn = 0;
		else if (!isSpace(*s) && !wordOn)
		{
			wordOn = 1;
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
 *Return: 1 on success or 0 on failure
 */
int isSpace(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

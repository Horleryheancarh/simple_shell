#include "main.h"

/**
 *checkPath - search for dir of cmd
 *@build: input field
 *
 *Return: 1 on success or 0 on failure
 */
int checkPath(config *build)
{
	register int len;
	static char buffer[BUFSIZE];
	struct stat st;
	char *tok, *copy, *delim = ":", *temp;
	int inLoop = 0;

	if (checkEdgeCases(build))
		return (1);
	copy = _strdup(build->path);
	tok = _strtok(copy, delim);
	while (tok)
	{
		temp = inLoop ? tok - 2 : tok;
		if (*temp == 0 && stat(build->args[0], &st) == 0)
		{
			build->fullPath = build->args[0];
			free(copy);
			return (1);
		}
		len = _strlen(tok) + _strlen(build->args[0]) + 2;
		_strcat(buffer, tok);
		_strcat(buffer, "/");
		_strcat(buffer, build->args[0]);
		insertNullByte(buffer, len - 1);
		if (stat(buffer, &st) == 0)
		{
			free(copy);
			build->fullPath = buffer;
			return (1);
		}
		insertNullByte(buffer, 0);
		tok = _strtok(NULL, delim);
		inLoop = 1;
	}
	build->fullPath = build->args[0];
	free(copy);
	return (0);
}

/**
 *checkEdgeCases - helper func for checkPath
 *@build: input field
 *
 *Return: 1 on success or 0 on failure
 */
int checkEdgeCases(config *build)
{
	char *copy;
	struct stat st;

	copy = _strdup(build->path);

	if (!copy)
	{
		build->fullPath = build->args[0];
		free(copy);
		return (1);
	}

	if (*copy == ':' && stat(build->args[0], &st) == 0)
	{
		build->fullPath = build->args[0];
		free(copy);
		return (1);
	}

	free(copy);
	return (0);
}

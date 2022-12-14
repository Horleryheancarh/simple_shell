#include "main.h"

/**
 *_getenv - retrieve env variable
 *@s: String
 *@environ: local environment
 *
 *Return: integer
 */
char *_getenv(char *s, char **environ)
{
	register int i = 0;
	char *tok, *status;

	while (environ[i])
	{
		tok = _strtok(environ[i], "=");
		if (_strcmp(tok, s) == 0)
		{
			status = _strtok(NULL, "=");
			return (status);
		}
		i++;
	}
	return (NULL);
}

/**
 *envFunc - print the environ
 *@build: input field
 *
 *Return: 1
 */
int envFunc(config *build)
{
	printList(build->env);
	return (1);
}

/**
 *setenvFunc - adds env variable or modify existing env
 *@build: input field
 *
 *Return: 1
 */
int setenvFunc(config *build)
{
	register int index, len;
	static char buffer[BUFSIZE];

	if (countArgs(build->args) != 3)
	{
		errno = EWSIZE;
		errorHandler(build);
		return (1);
	}

	len = _strlen(build->args[1]) + _strlen(build->args[2]) + 2;
	_strcat(buffer, build->args[1]);
	_strcat(buffer, "=");
	_strcat(buffer, build->args[2]);
	insertNullByte(buffer, len - 1);
	index = searchNode(build->env, build->args[1]);

	if (index == -1)
	{
		addNodeEnd(&build->env, buffer);
		insertNullByte(buffer, 0);
		return (1);
	}

	deleteNodeAtIndex(&build->env, index);
	addNodeAtIndex(&build->env, index, buffer);
	insertNullByte(buffer, 0);
	return (1);
}

/**
 *unsetenvFunc - deletes env variable if exists
 *@build: input field
 *
 *Return: (1);
 */
int unsetenvFunc(config *build)
{
	register int foundVar, i = 1;
	int foundMatch = 0;

	while (build->args[i])
	{
		if (_isalpha(build->args[i][0]) || build->args[i][0] == '_')
		{
			foundVar = searchNode(build->env, build->args[i]);

			if (foundVar > -1)
			{
				deleteNodeAtIndex(&build->env, foundVar);
				foundMatch = 1;
			}
		}
		i++;
	}
	if (foundMatch == 0)
	{
		errno = ENOSTRING;
		errorHandler(build);
	}
	return (1);
}

/**
 *_isalpha - checks if a is an alphabet
 *@a: character
 *
 *Return: if a is an alphabet return 1 else 0
 */
int _isalpha(int a)
{
	if (a > 64 && a < 91)
		return (1);
	else if (a > 96 && a < 123)
		return (1);
	else
		return (0);
}

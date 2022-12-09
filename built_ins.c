#include "main.h"

/**
 *findBuiltIns - validates if cmd is a builtin
 *@build: build parameters
 *
 *Return: true or false
 */
_Bool findBuiltins(config *build)
{
	register int i = 0;
	type_b getBuiltIns[] = {
		{"exit", exitFunc},
		{"env", envFunc},
		{"history", historyFunc},
		{"alias", aliasFunc},
		{"cd", cdFunc},
		{"setenv", setenvFunc},
		{"unsetenv", unsetenvFunc},
		{"help", helpFunc},
		{NULL, NULL}
	};

	while (getBuiltIns[i].command)
	{
		if (_strcmp(build->args[0], getBuiltIns[i].command) == 0)
		{
			getBuiltIns[i].func(build);
			freeArgsAndBuffer(build);
			return (true);
		}
		i++;
	}

	return (false);
}

/**
 *exitFunc - exits the application
 *@build: input field
 *
 *Return: 1 on success 0 on failure
 */
int exitFunc(config *build)
{
	register int argCount, exitStatus;

	argCount = countArgs(build->args);
	if (argCount == 1)
	{
		freeMembers(build);

		if (build->errorStatus)
			exit(build->errorStatus);
		exit(EXIT_SUCCESS);
	}
	else if (argCount > 1)
	{
		exitStatus = _atoi(build->args[1]);
		if (exitStatus == -1)
		{
			errno = EILLEGAL;
			build->errorStatus = 2;
			errorHandler(build);
			return (0);
		}
		freeMembers(build);
		exit(exitStatus);
	}
	return (1);
}

/**
 *historyFunc - displays command history
 *@build: input field
 *
 *Return: 1 on success, 0 on failure
 */
int historyFunc(config *build)
{
	char *str = "Currently in development\n";

	(void) build;
	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}

/**
 *aliasFunc - displays local aliases
 *@build: input field
 *
 *Return: 1 on success, 0 on failure
 */
int aliasesFunc(config *build)
{
	char *str = "Currently in development\n";

	(void) build;
	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}
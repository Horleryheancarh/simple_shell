#include "main.h"

/**
 *helpFunc - retrieve instructions
 *@build: input field
 *
 *Return: integer
 */
int helpFunc(config *build)
{
	type_b help_arr[] = {
		{"exit", helpExit}, {"env", helpEnv}, {"history", helpHistory},
		{"alias", helpAlias}, {"cd", helpCd}, {"setenv", helpSetenv},
		{"unsetenv", helpUnsetenv}, {"help", helpHelp}, {NULL, NULL}
	};
	register int i, j = 1, argCount = countArgs(build->args);
	_Bool foundCommand = false;

	if (argCount == 1)
		return (displayHelpMenu());
	while (j < argCount)
	{
		i = 0;
		while (help_arr[i].command)
		{
			if (_strcmp(build->args[j], help_arr[i].command) == 0)
			{
				foundCommand = true;
				help_arr[i].func(build);
				break;
			}
			i++;
		}
		j++;
	}

	if (foundCommand == false)
	{
		errno = ENOBUILTIN;
		errorHandler(build);
	}

	return (1);
}

/**
 *displayHelpMenu - display available help options
 *
 *Return: integer
 */
int displayHelpMenu(void)
{
	char s[81] = "Type help [built-in]\n\nIncluded built-ins";
	char *str = "\n\n\texit\n\tenv\n\tcd\n\tsetenv\n\tunsetenv\n\thelp\n";

	_strcat(s, str);
	write(STDOUT_FILENO, s, _strlen(s));
	return (1);
}

/**
 *helpExit - instruction on exit
 *@build: input field
 *
 *Return: integer
 */
int helpExit(config *build)
{
	char s[] = "exit: exit [n]\n\tExit the shell.\n\n\t";
	char *str = "Exit with a status of n, or if n is omitted, 0.\n";

	(void)build;
	_strcat(s, str);
	write(STDOUT_FILENO, s, _strlen(s));
	return (1);
}

/**
 *helpEnv - instruction on env
 *@build: input field
 *
 *Return: integer
 */
int helpEnv(config *build)
{
	char s[] = "env: env\n\tPrint the environment.\n";

	(void)build;
	write(STDOUT_FILENO, s, _strlen(s));
	return (1);
}

/**
 *helpHistory - instruction on history
 *@build: input field
 *
 *Return: integer
 */
int helpHistory(config *build)
{
	char s[] = "history: history\n\tNot supported in this version.\n";

	(void)build;
	write(STDOUT_FILENO, s, _strlen(s));
	return (1);
}
































#include "main.h"

/**
 *helpAlias - instructions on aliases
 *@build: input field
 *
 *Return: integer
 */
int helpAlias(config *build)
{
	char s[] = "alias: alias\nNot supported in this version.\n";

	(void)build;
	write(STDOUT_FILENO, s, _strlen(s));
	return (1);
}

/**
 *helpCd - instructions on change directory
 *@build: input field
 *
 *Return: integer
 */
int helpCd(config *build)
{
	char s[192] = "cd: cd [destinaation]\n\t";
	char *str1 = "Change directory to target destination.\n\t";
	char *str2 = "If [destination] is omitted, user will taken to home.\n\t";
	char *str3 = "If '.' is used as second argument, user will be taken to ";
	char *str4 = "last directory.\n";

	(void)build;
	_strcat(s, str1);
	_strcat(s, str2);
	_strcat(s, str3);
	_strcat(s, str4);

	write(STDOUT_FILENO, s, _strlen(s));
	return (1);
}

/**
 *helpSetenv - instruction on setenv
 *@build: input field
 *
 *Return: integer
 */
int helpSetenv(config *build)
{
	char s[186] = "setenv: setenv [var] [value]\n\t";
	char *str1 = "Set or update a variable in the environment.\n\t";
	char *str2 = "Creates a variable [var] with [value]. If the [var] ";
	char *str3 = "already exists in the environment, the value is update.\n";

	(void)build;
	_strcat(s, str1);
	_strcat(s, str2);
	_strcat(s, str3);
	write(STDOUT_FILENO, s, _strlen(s));
	return (1);
}

/**
 *helpUnsetenv - instruction on unsetenv
 *@build: input field
 *
 *Return: integer
 */
int helpUnsetenv(config *build)
{
	char s[116] = "unsetenv: unsetenv [var]\n\t";
	char *str1 = "Unset a variable in the environment.\n\n\t";
	char *str2 = "[var] is an existing variable in the environment.\n";

	(void)build;
	_strcat(s, str1);
	_strcat(s, str2);
	write(STDOUT_FILENO, s, _strlen(s));
	return (1);
}

/**
 *helpHelp - instruction on help
 *@build: input field
 *
 *Return: integer
 */
int helpHelp(config *build)
{
	char s[129] = "help: help [built-in]\n\t";
	char *str1 = "Display information about built-in commands.\n\n\tIf ";
	char *str2 = "[built-in] is not specified, print a list of built-ins.\n";

	(void)build;
	_strcat(s, str1);
	_strcat(s, str2);
	write(STDOUT_FILENO, s, _strlen(s));
	return (1);
}

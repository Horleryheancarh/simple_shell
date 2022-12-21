#include "main.h"


/**
 *cdFunc - execute cd builtin
 *@build: input field
 *
 *Return: 1 on success, 0 on failure
 */
int cdFunc(config *build)
{
	register uint count = 0;
	int ableToChange = 0;

	count = countArgs(build->args);
	if (count == 1)
		ableToChange = cdToHome(build);
	else if (count == 2 && _strcmp(build->args[1], "-") == 0)
		ableToChange = cdToPrevious(build);
	else
		ableToChange = cdToCustom(build);

	if (ableToChange == 1)
		updateEnviron(build);

	return (1);
}

/**
 *cdToHome - change dir to home
 *@build: input field
 *
 *Return: 1 on success, 0 on failure
 */
int cdToHome(config *build)
{
	register int i;
	char *s, *p;

	i = searchNode(build->env, "HOME");
	if (i == -1)
		return (1);

	s = getNodeAtIndex(build->env, i);
	p = _strchr(s, '=');
	p++;
	chdir(p);
	free(s);

	return (1);
}

/**
 *cdToPrevious - change dir to previous
 *@build: input field
 *
 *Return: 1 on success, 0 on failure
 */
int cdToPrevious(config *build)
{
	register int i;
	char *s, *p;
	char *current = NULL;

	current = getcwd(current, 0);
	i = searchNode(build->env, "OLDPWD");

	if (i == -1)
	{
		chdir(current);
		write(STDOUT_FILENO, current, _strlen(current));
		displayNewLine();
		return (1);
	}

	s = getNodeAtIndex(build->env, i);
	p = _strchr(s, '=');
	p++;

	chdir(p);
	write(STDOUT_FILENO, p, _strlen(p));
	displayNewLine();
	free(s);
	return (1);
}

/**
 *cdToCustom - change dir to input
 *@build: input field
 *
 *Return: 1 on success, 0 on failure
 */
int cdToCustom(config *build)
{
	register int changeStatus;

	changeStatus = chdir(build->args[1]);
	if (changeStatus == -1)
	{
		errno = EBADCD;
		errorHandler(build);
		return (0);
	}

	return (1);
}

/**
 *updateEnviron - change environment var
 *@build: input field
 *
 *Return: true on success, false on failure
 */
int updateEnviron(config *build)
{
	register int i;

	i = updateOld(build);
	updateCur(build, i);
	return (1);
}

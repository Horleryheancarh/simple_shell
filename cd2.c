#include "main.h"

/**
 *updateOld - updates OLDPWD to current PWD
 *@build: input field
 *
 *Return: index in linked list of PWD on success
 */
int updateOld(config *build)
{
	register int pwdI = 0, i = 0;

	static char old[BUFSIZE];
	char *curr = NULL;

	_strcat(old, "OLD");
	pwdI = searchNode(build->env, "PWD");
	if (pwdI == -1)
		return (-1);

	curr = getNodeAtIndex(build->env, pwdI);
	_strcat(old, curr);

	insertNullByte(old, _strlen(curr) + 4);
	free(curr);
	i = searchNode(build->env, "OLDPWD");
	if (i == -1)
		return (-1);

	deleteNodeAtIndex(&build->env, i);
	addNodeAtIndex(&build->env, i, old);
	insertNullByte(old, 0);

	return (pwdI);
}

/**
 *updateCur - updates PWD to accurately reflect current dir
 *@build: input field
 *@i: index in linked list
 *
 *Return: true on success, false on failure
 */
_Bool updateCur(config *build, int i)
{
	static char tmp[BUFSIZE], cwd[BUFSIZE];

	getcwd(tmp, BUFSIZE);
	_strcat(cwd, "PWD=");
	_strcat(cwd, tmp);

	if (i > -1)
	{
		deleteNodeAtIndex(&build->env, i);
		addNodeAtIndex(&build->env, i, cwd);
	} else
		addNodeAtIndex(&build->env, 0, cwd);

	insertNullByte(tmp, 0);
	insertNullByte(cwd, 0);
	return (true);
}

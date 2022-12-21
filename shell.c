#include "main.h"

/**
 *shell - simple shell
 *@build: input field
 *
 *Return: void
 */
void shell(config *build)
{
	while (true)
	{
		checkAndGetLine(build);

		if (splitString(build) == false)
			continue;

		if (findBuiltIns(build) == true)
			continue;

		checkPath(build);
		forkAndExecute(build);
	}
}

/**
 *checkAndGetLine - check stdin and retrieves next line
 *@build: input field
 *
 *Return: void
 */
void checkAndGetLine(config *build)
{
	register int len;
	size_t bufferSize = 0;
	char *p1, *p2;

	build->args = NULL;
	build->envList = NULL;
	build->lineCounter++;

	if (isatty(STDIN_FILENO))
		displayPrompt();

	len = getline(&build->buffer, &bufferSize, stdin);
	if (len == EOF)
	{
		freeMembers(build);
		if (isatty(STDIN_FILENO))
			displayNewLine();
		if (build->errorStatus)
			exit(build->errorStatus);
		exit(EXIT_SUCCESS);
	}

	p1 = _strchr(build->buffer, '\n');
	p2 = _strchr(build->buffer, '\t');

	if (p1 || p2)
		insertNullByte(build->buffer, len - 1);

	stripComments(build->buffer);
}

/**
 *stripComments - remove comments from input
 *@s: String
 *
 *Return: void
 */
void stripComments(char *s)
{
	register int i = 0;
	int notFirst = 0;

	while (s[i])
	{
		if (i == 0 && s[i] == '#')
		{
			insertNullByte(s, i);
			return;
		}

		if (notFirst == 0)
		{
			if (s[i] == '#' && s[i - 1] == ' ')
			{
				insertNullByte(s, i);
				return;
			}
		}
		i++;
		notFirst = 1;
	}
}

/**
 *forkAndExecute - fork current build and execute
 *@build: input field
 *
 *Return: void
 */
void forkAndExecute(config *build)
{
	int status;
	pid_t f = fork();

	convertLLtoArr(build);
	if (f == -1)
	{
		perror("error\n");
		freeMembers(build);
		freeArgs(build->envList);
		exit(1);
	}
	else if (f == 0)
	{
		if (execve(build->fullPath, build->args, build->envList) == -1)
		{
			errorHandler(build);
			freeMembers(build);
			freeArgs(build->envList);
			if (errno == ENOENT)
				exit(127);
			if (errno == EACCES)
				exit(126);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			build->errorStatus = WEXITSTATUS(status);
		freeArgsAndBuffer(build);
		freeArgs(build->envList);
	}
}

/**
 *convertLLtoArr - convert linked list to array
 *@build: input field
 *
 *Return: void
 */
void convertLLtoArr(config *build)
{
	register int i = 0;
	size_t count = 0;
	char **envList = NULL;
	linked_l *temp = build->env;

	count = list_len(build->env);
	envList = malloc(sizeof(char *) * (count + 1));
	if (!envList)
	{
		perror("Malloc failed\n");
		exit(1);
	}

	while (temp)
	{
		envList[i] = _strdup(temp->string);
		temp = temp->next;
		i++;
	}

	envList[i] = NULL;
	build->envList = envList;
}

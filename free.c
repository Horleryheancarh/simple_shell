#include "main.h"

/**
 *freeMembers - frees build config
 *@build: input field
 *
 *Return: void
 */
void freeMembers(config *build)
{
	if (build->env)
		freeList(build->env);

	if (build->args)
		freeArgs(build->args);

	if (build->buffer)
		free(build->buffer);
}

/**
 *freeArgsAndBuffer - frees args and buffer
 *@build: input field
 *
 *Return: void
 */
void freeArgsAndBuffer(config *build)
{
	freeArgs(build->args);

	free(build->buffer);
}

/**
 *freeList - free a linked list
 *@head: head of the list
 *
 *Return: void
 */
void freeList(linked_l *head)
{
	linked_l *temp;
	linked_l *new;

	if (!head)
		return;

	new = head;

	while (new)
	{
		temp = new;
		new = temp->next;
		free(temp->string);
		free(temp);
	}

	head = NULL;
}

/**
 *freeArgs - free build->args
 *@args: array of char
 *
 *Return: void
 */
void freeArgs(char **args)
{
	register uint i = 0;

	while (args[i])
		free(args[i++]);

	free(args);
}

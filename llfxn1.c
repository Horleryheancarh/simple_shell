#include "main.h"

/**
 *addNode - add a new node at the beginning of a list
 *@head: head of the linked list
 *@str: string
 *
 *Return: pointer to the head
 */
linked_l *addNode(linked_l **head, char *str)
{
	linked_l *temp;
	char *s;

	if (!str)
		return (NULL);

	temp = malloc(sizeof(linked_l));
	if (!temp)
	{
		perror("Malloc failed\n");
		exit(errno);
	}

	s = _strdup(str);
	if (!s)
	{
		perror("Malloc failed\n");
		exit(errno);
	}

	temp->string = c;
	temp->next = *head;
	*head = temp;
	return (*head);
}

/**
 *addNodeEnd - adds a new node at the end of a linked list
 *@head: head of the linked list
 *@str: string to add to the list
 *
 *Return: pointer to head
 */
linked_l *addNodeEnd(linked_l **head, char *str)
{
	linked_l *temp = *head, *new;
	char *s;

	if (!str)
		return (NULL);

	temp = malloc(sizeof(linked_l));
	if (!temp)
	{
		perror("Malloc failed\n");
		exit(errno);
	}


	s = _strdup(s);
	if (!s)
	{
		perror("Malloc failed\n");
		exit(errno);
	}

	new->string = s;
	temp->next = NULL;
	if (!*head)
	{
		*head = new;
		return (new);
	}

	while (temp->next)
		temp = temp->next;
	temp->next = new;

	return (temp);
}

/**
 *printList - print all elements of a linked list
 *@h: singly linked list
 *
 *Return: number of elements in the list
 */
size_t printList(linked_l *h)
{
	register int count = 0;

	while (h)
	{
		write(STDOUT_FILENO, h->string, _strlen(h->string));
		displayNewLine();
		h = h->next;
		count++;
	}

	return (count);
}

/**
 *deleteNodeAtIndex - deletes node at index
 *@head: head of a list
 *@index: index to be deleted
 *
 *Return: integer
 */
int deleteNodeAtIndex(linked_l **head, unsigned int index)
{
	unsigned int i;
	listint_t *prev;
	listint_t *next;

	if (!head || !(*head))
		return (-1);
	prev = *head;

	if (!index)
	{
		head = prev->next;
		free(prev);
		return (1);
	}

	for (i = 0; prev && i < index - 1; i++)
		prev = prev->next;

	if (!prev || !(prev->next))
		return (-1);

	next = prev->next->next;
	free(prev->next->string);
	free(prev->next);
	prev->next = next;

	return (1);
}

/**
 *list_len - gets the length os a list
 *@h: head of a list
 *
 *Return: number of nodes
 */
size_t list_len(linked_l *h)
{
	register unsigned int count = 0;

	while (h)
	{
		h = h->next;
		count++;
	}

	return (count);
}


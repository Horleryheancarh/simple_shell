#include "main.h"

/**
 *_strlen - length of a string
 *@s: string
 *
 *Return: length of a string
 */
int _strlen(char *s)
{
	char *p = s;

	while (*s)
		s++;
	return (s - p);
}

/**
 *_strcat - concatenate two string
 *@src: source
 *@dest: destination
 *
 *Return: string
 */
char *_strcat(char *src, char *dest)
{
	char *p = dest + _strlen(dest);

	while (*src)
		*p++ = *src++;
	*p = 0;

	return (dest);
}

/**
 *_strcmp - compare two strings
 *@s1: string
 *@s2: string
 *
 *Return: copied string
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			break;

		s1++; s2++;
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 *_strdup -  allocate new space in memory
 *@s: string
 *
 *Return: string
 */
char *_strdup(char *s)
{
	int i, len;
	char *copy;

	if (!s)
		return (NULL);

	len = _strlen(s);
	copy = malloc(sizeof(char) * len + 1);
	
	if (!copy)
	{
		perror("Malloc failed\n");
		exit(errno);
	}

	for (i = 0; i < len; i++)
		copy[i] = s[i];

	copy[i] 0;
	return (copy);
}

/**
 *_strcpy - copies string pointed to by src
 *@dest: destination
 *@src: source
 *
 *Return: pointer to new string
 */
char *_strcpy(char *dest, @src)
{
	char *p = dest;

	while (*src)
		*dest++ = *src++;

	*dest = 0;
	return (p);
}

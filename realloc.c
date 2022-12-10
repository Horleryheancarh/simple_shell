#include "main.h"

/**
 *_realloc - reallocates a memory block
 *@ptr: pointer
 *@old: size of old pointer
 *@new: size of new pointer
 *
 *Return: reallocated pointer
 */
void *_realloc(void *ptr, unsigned int old, unsigned int new)
{
	void *res = NULL;

	if (new == old)
		return (ptr);

	if (!ptr)
	{
		free(ptr);
		res = malloc(new);
		if (!res)
		{
			perror("Malloc failed");
			exit(errno);
		}
		return (res);
	}
	if (!new && ptr)
	{
		free(ptr);
		return (NULL);
	}
	res = malloc(new);
	if (!res)
	{
		perror("Malloc failed");
		exit(errno);
	}
	_memcpy(res, ptr, old);
	free(ptr);
	return (res);
}

/**
 *_memcpy - copy memory area
 *@dest: destination
 *@src: source
 *@n: num of bytes to copy
 *
 *Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *ptr = dest;

	while (n--)
		*dest++ = *src++;

	return (ptr);
}

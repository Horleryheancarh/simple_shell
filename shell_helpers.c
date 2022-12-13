#include "main.h"

/**
 *insertNullByte - inserts null byte at a given index
 *@s: input string
 *@n: index
 *
 *Return: void
 */
void insertNullByte(char *s, unsigned int n)
{
	s[n] = '\0';
}

/**
 *displayPrompt - display shell prompt
 *
 *Return: void
 */
void displayPrompt(void)
{
	write(STDERR_FILENO, "$ ", 2);
}

/**
 *displayNewLine - add new line
 *
 *Return: void
 */
void displayNewLine(void)
{
	write(STDOUT_FILENO, "\n", 1);
}


/**
 *sigintHandler - catches SIGINT and reset it
 *@n: signal from stdint
 *
 *Return: void
 */
void sigintHandler(int n)
{
	(void)n;
	signal(SIGINT, sigintHandler);
	displayNewLine();
	displayPrompt();
	fflush(stdout);
}

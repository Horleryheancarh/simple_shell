#include "main.h"

/**
 *errorHandler - print error message
 *@build: input field
 *
 *Return: void
 */
void errorHandler(config *build)
{
	register int len;
	static char error[BUFSIZE];
	char *ptr, *alpha;

	alpha = itoa(build->lineCounter);
	_strcat(error, build->shellName);
	_strcat(error, ": ");
	_strcat(error, alpha);
	_strcat(error, ": ");
	_strcat(error, build->args[0]);
	_strcat(error, getErrorMessage);
	if (build->args[1])
	{
		if (errno != EBADCD)
			_strcat(error, ": ");
		_strcat(error, build->args[1]);
	}
	_strcat(error, "\n");
	ptr = _strchr(error, "\n");
	len = ptr - error;
	write(STDERR_FILENO, error, len + 1);
	free(alpha);
	insertNullByte(error, 0);
}

/**
 *getErrorMessage - match errno to string
 *
 *Return: String
 */
char *getErrorMessage(void)
{
	char *s;

	switch (errno)
	{
		case EBADCD:
			s = ": can't cd to ";
			break;
		case ENOENT:
			s = ": not found ";
			break;
		case ENOSTRING:
			s = ": bad variable name ";
			break;
		case EILLEGAL:
			s = ": Illegal number ";
			break;
		case EWSIZE:
			s = ": invalid number of arguments ";
			break;
		case ENOBUILTIN:
			s = ": type help for a list of built-ins ";
			break;
		case EACCES:
			s = ": Permission denied ";
			break;
		default:
			s = ": no error numbeer assigned";
	}

	return (s);
}

/**
 *countDigits - count number of digits in a number
 *@n: input number
 *
 *Return: num of digits
 */
unsigned int countDigits(int n)
{
	register int i = 0;

	while (n > 0)
	{
		n /= 10;
		i++;
	}

	return (i);
}

/**
 *itoa - convert integer to string
 *@n: number
 *
 *Return: String
 */
char *itoa(unsigned int n)
{
	register int i = 0;
	char *s;

	i += countDigits(n);
	s = malloc(sizeof(char) * (i + 1));

	if (!s)
	{
		perror("Malloc: failed\n");
		exit(errno);
	}

	insertNullByte(s, i);

	while (n > 0)
	{
		s[i - 1] = num % 10 + '0';
		num = num / 10;
		i--;
	}

	return (s);
}

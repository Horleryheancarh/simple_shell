#include "main.h"

/**
 *main - Entry point
 *@ac: argument count
 *@av: argument vector
 *
 *Return: 0
 */
int main(int ac, char **av)
{
	config build;

	void (ac);
	signal(SIGINT, sigintHandler);
	configInit(&build);
	build.shellName = av[0];
	shell(&build);

	return (0);
}

/**
 *configInit - init values for config struct
 *@build: input
 *
 *Return: initialized build
 */
config *configInit(config *build)
{
	build->env = generateLinkedList(environ);
	build->envList = NULL;
	build-> args = NULL;
	build->buffer = NULL;
	build->path = _getenv("PATH", environ);
	build->fullPath = NULL;
	build->lineCounter = 0;
	build->shellName = NULL;
	build->errorStatus = 0;

	return (build);
}

#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>
#include <limits.h>

/* ERRORS */
#define BUFSIZE 256
#define ENOSTRING 1106
#define EILLEGAL 227
#define EWSIZE 410
#define ENOBUILTIN 415
#define EBADCD 726

extern char **environ;

/*
 *struct linkedList - linked list data structure
 *@string: environ path name
 *@next: pointer to next node
 */
typedef struct linkedList
{
	char *string;
	struct linkedList *next;
} linked_l;

/**
 *struct configurations - build settings
 *@env: linked list of local env
 *@envList: array env to pass into execve
 *@args: array of arguments
 *@buffer: input buffer
 *@path: array of $PATH locations
 *@fullPath: string of path
 *@shellName: name of shell (argv[0])
 *@lineCounter: count lines users have entered
 *@errorStatus: error status of last child process
 */
typedef struct configurations
{
	linked_l *env;
	char **envList;
	char *args;
	char *buffer;
	char *path;
	char *fullPath;
	char *shellName;
	unsigned int lineCounter;
	int errorStatus;
} config;

/**
 *struct: buuiltInCommands - commands and fxns associated with it
 *@command: input command
 *@func: output fxn
 */
typedef struct builtInCommands
{
	char *command;
	int (*func)(config *build);
} type_b;

/* main */
config *configInit(config *build);

/* built_ins */
_Bool findBuiltIns(config *build);
int exitFunc(config *build);
int historyFunc(config *build);
int aliasFunc(config *build);

/* cd */

/* env */

/* help */

/* built_in_helpers */

/* shell */

/* shell_helpers */

/* error_handler */

/* check_path */

/* split_string */

/* string_helpers */

/* linkedlist_fxn */

/* realloc_mem */

/* free_mem */

/* welcome_text */

#endif

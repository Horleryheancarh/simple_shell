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
config *configInit(config *);

/* built_ins */
_Bool findBuiltIns(config *);
int exitFunc(config *);
int historyFunc(config *);
int aliasFunc(config *);

/* cd */

/* env */
int envFunc(config *);
int setenvFunc(config *);
int unsetenvFunc(config *);
int _isalpha(int);

/* help */

/* built_in_helpers */
int countArgs(char **);
int _atoi(char *);

/* shell */

/* shell_helpers */
void insertNullByte(char *, unsigned int);
void displayPrompt(void);
void displayNewLine(void);
void sigintHandler(int);

/* error_handler */
void errorHandler(config *);
unsigned int countDigits(int);
char *getErrorMessage(void);
char *itoa(unsigned int);

/* check_path */
_Bool checkPath(config *);
_Bool checkEdgeCases(config *);

/* split_string */
_Bool splitString(config *);
unsigned int countWords(char **);
_Bool isSpace(char);

/* string_helpers */
int _strlen(char *);
char *_strcat(char *, char *);
int _strcmp(char *, char *);
char *_strdup(char *);
char *_strcpy(char *, char *);
char *_strtok(char *, char *);
int _strcspn(char *, char *);
char *_strchr(char *, char);

/* linkedlist_fxn */

/* realloc_mem */
void *_realloc(void *, unsigned int, unsigned int);
char *_memcpy(char *, char *, unsigned int);

/* free_mem */
void freeMembers(config *);
void freeArgsAndBuffer(config *);
void freeArgs(char **);
void freeList(linked_l *);


/* welcome_text */

#endif

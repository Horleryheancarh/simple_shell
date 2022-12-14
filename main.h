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
	char **args;
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
int findBuiltIns(config *);
int exitFunc(config *);
int historyFunc(config *);
int aliasFunc(config *);

/* cd */
int cdFunc(config *);
int updateOld(config *);
int updateCur(config *, int);
int updateEnviron(config *);
int cdToHome(config *);
int cdToPrevious(config *);
int cdToCustom(config *);


/* env */
int envFunc(config *);
int setenvFunc(config *);
int unsetenvFunc(config *);
int _isalpha(int);
char *_getenv(char *, char **);

/* help */
int helpFunc(config *);
int displayHelpMenu(void);
int helpExit(config *);
int helpEnv(config *);
int helpHistory(config *);
int helpAlias(config *);
int helpCd(config *);
int helpSetenv(config *);
int helpUnsetenv(config *);
int helpHelp(config *);

/* built_in_helpers */
int countArgs(char **);
int _atoi(char *);

/* shell */
void shell(config *);
void checkAndGetLine(config *);
void forkAndExecute(config *);
void convertLLtoArr(config *);
void stripComments(char *);

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
int checkPath(config *);
int checkEdgeCases(config *);

/* split_string */
int splitString(config *);
unsigned int countWords(char *);
int isSpace(char);

/* string_helpers */
int _strlen(char *);
char *_strcat(char *, char *);
int _strcmp(char *, char *);
char *_strdup(char *);
char *_strcpy(char *, char *);
char *_strtok(char *, char *);
int _strcspn(char *, char *);
char *_strchr(char *, char);

/* llfxn */
char *getNodeAtIndex(linked_l *, unsigned int);
int deleteNodeAtIndex(linked_l **, unsigned int);
int searchNode(linked_l *, char *);
size_t list_len(linked_l *);
size_t printList(linked_l *);
linked_l *addNode(linked_l **, char *);
linked_l *addNodeEnd(linked_l **, char *);
linked_l *generateLinkedList(char **);
linked_l *addNodeAtIndex(linked_l **, int, char *);

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

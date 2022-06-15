#ifndef _SHELL_H_
#define _SHELL_H_
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "args.h"

void exit_handle(char **u_tokns, char *line);
char *_strtok(char *s, const char *delim);
unsigned int _strlen(char *s);
/* string02.c */
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
char *_strcat(char *s1, char *s2, list_t **mt);

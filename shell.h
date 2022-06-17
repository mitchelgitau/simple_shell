#ifndef _SHELL_H_
#define _SHELL_H_

#include <dirent.h>
#include <limits.h>
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
#include <string.h>

#define MAXLEN 100
#define STDIN 0
#define STAT_FAILURE 1
#define EXEC_FAILURE 2
#define PROMPT "#cmd$ "

#define LOGFILE ".simple_shell_history"
#define MAXLOGSIZE 4096
#define MAXBUFREAD 1024

int fetch_token(void);
int switch_mode(int ac, char **av, char **env);
int stat_exec(char **str, int i);
char *which_command(char *command);
char *search_paths(char *token_path, char *command);
int cmd(int ac, char **av, char **env);

void exit_handle(char **u_tokns, char *line);
char *_strtok(char *s, const char *delim);
unsigned int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);

#endif /* _SHELL_H_ */

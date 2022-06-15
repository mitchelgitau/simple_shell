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
#include <string.h>
#include "args.h"

#define MAXLEN 100
#define STDIN 0
#define PROMPT "#cmd$ "

#define LOGFILE ".simple_shell_history"
#define MAXLOGSIZE 4096
#define MAXBUFREAD 1024

/* log01.c */
int _add_log(sev *ptr_sev);
int _write_log(sev *ptr_sev);
int _log_count(sev *ptr_sev);

int get_input(void);
int switch_args(int ac, char **av);
int get_args();
int get_path();
int print_path(int ac, char **av, char **env);
int print_env(int ac, char **av, char **env);
int cmd(int ac, char **av, char **env);

void exit_handle(char **u_tokns, char *line);
char *_strtok(char *s, const char *delim);
unsigned int _strlen(char *s);
/* string02.c */
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
char *_strcat(char *s1, char *s2, list_t **mt);

#endif /* _SHELL_H_ */
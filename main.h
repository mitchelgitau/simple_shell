#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100
#define STDIN 0
#define PROMPT "#cmd$ "

int get_input(void);
int switch_args(int ac, char **av);
int get_args();
int get_path();
int cmd(int ac, char **av, char **env);

#endif /* MAIN_H */
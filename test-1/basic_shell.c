#include "main.h"
/**
 * main - super simple shell that can run commands with their
 * full path, without any argument 
 * 
 * Return : Always 0
 */
int main(int ac, char *av[])
{
    int wstate; /* status, i = 1; */
    pid_t parent_pid, child_pid;
    ssize_t nchar;
    size_t len = MAXLEN;
    /*struct stat statbuf; */
    char **lineptr = malloc(sizeof(char) * MAXLEN);
    char **token_arg = malloc(sizeof(char) * MAXLEN);
    FILE *instream = malloc(sizeof(char) * MAXLEN);
    char *delim = " ,;\t";
    char *command[] = {"/bin/ls"};
    char *prompt = "#cisfun$ ";

    if (ac != 1)
        printf("Usage Error : %s ", av[0]);

    parent_pid = getpid();
    printf("%s", prompt);
    printf("Welcome to the shell of the future!\n");
    printf("%s", prompt);
    printf("(%u) HAWKEYE is watching !!\n", parent_pid);

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Child Error");
        return (1);
    }
    if (child_pid == 0)
    {
        printf("%s", prompt);
        printf("%s\n", command[0]);
        printf("Files in your directory :)\n");
        if(execve(command[0], command, NULL) == -1)
            perror("Execution Error");
        instream = fdopen(0, "r");
        if (instream == NULL) {
            perror("fopen");
            return (1);
        }
        while((nchar = getline(lineptr, &len, instream)) != -1 && nchar != EOF)
        {
            while((*token_arg = strtok(*lineptr++, delim)) != NULL)
            {
                *token_arg[-1] = '';
                if (execve(token_arg[0], token_arg, NULL) == -1)
                {
                    perror("Token Execution Error");
                    printf("%ld\n", strlen(token_arg[0]));
                    printf("(%c)\n", *token_arg[-1]);
                }
            }
            /*
            if ((status = stat(*token_arg[0], &statbuf)) != -1)
            {
            }
            else
                perror("Stat Error"); */
        }
    }
    else
    {
        wait(&wstate);
        printf("%s", prompt);
        printf("(%u) Thank you for your service !!\n", child_pid);
    }
    free(token_arg);
    free(lineptr);
    return (0);
}
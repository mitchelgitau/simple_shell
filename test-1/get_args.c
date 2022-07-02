#include "shell.h"
/**
 * get_args - get input with args from stream
 * advanced
 * 
 * Return : Always 0
 */
int get_args()
{
    struct stat statbuf;
    ssize_t numchar;
    size_t len = MAXLEN;
    char **lineptr = malloc(sizeof(char) * MAXLEN);
    char **token_str = malloc(sizeof(char) * MAXLEN);
    FILE *instream = NULL;
    char *delim = " ,;\t";
    char *exit_str = "exit";

    instream = fdopen(STDIN, "r");
    if (instream == NULL)
    {
        perror("Fdopen Error");
        return (EXIT_FAILURE);
    }

    while ((numchar = getline(lineptr, &len, instream)) != -1 
        && numchar != EOF)
    {
        while((*token_str = strtok(*lineptr++, delim)) != NULL)
        {
            printf("%s", PROMPT);
            if (strncmp(*token_str, exit_str, strlen(exit_str)) == 0)
                _exit(EXIT_SUCCESS);
        
            if (stat(token_str[0], &statbuf) != 0)
            {
                perror("Stat Error");
            }
            if(execve(token_str[0], token_str, NULL) == -1)
            {
                perror("Execution Error");
            }
        }
    }
    free(token_str);
    free(lineptr);
    fclose(instream);
    return (EXIT_SUCCESS);
}
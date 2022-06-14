#include "main.h"
/**
 * get_env - get input with env from stream
 * advanced version
 * 
 * Return : Always 0
 */
int get_env()
{
    struct stat statbuf;
    ssize_t numchar;
    size_t len = MAXLEN;
    char **lineptr = malloc(sizeof(char) * MAXLEN);
    char **token_str = malloc(sizeof(char) * MAXLEN);
    char **absolute_token = malloc(sizeof(char) * MAXLEN);
    char *working_dir = NULL, *dirbuf = malloc(sizeof(char) * MAXLEN);
    FILE *instream = NULL;
    char *delim = " ,;\t";

    instream = fdopen(STDIN, "r");
    if (instream == NULL)
    {
        perror("Fdopen Error");
        return (EXIT_FAILURE);
    }

    if ((working_dir = getcwd(dirbuf, len)) == NULL)
    {
        perror("Get current working directory Error");
        return (EXIT_FAILURE);
    }

    while ((numchar = getline(lineptr, &len, instream)) != -1 
        && numchar != EOF)
    {
        while((*token_str = strtok(*lineptr++, delim)) != NULL)
        {
            if ((realpath(*token_str, *absolute_token)) == NULL)
            {
                perror("Realpath Error");
                return (EXIT_FAILURE);
            }
            
            printf("%s\n", absolute_token[0]);
            printf("%s", PROMPT);

            if (absolute_token[1] == NULL)
                strcat(*absolute_token, working_dir);
                
            if (stat(absolute_token[0], &statbuf) != 0)
            {
                perror("Stat Error");
                return(EXIT_FAILURE);
            }
            if(execve(absolute_token[0], absolute_token, NULL) == -1)
            {
                perror("Execution Error");
                return (EXIT_FAILURE);
            }
        }
    }
    free(dirbuf);
    free(absolute_token);
    free(token_str);
    free(lineptr);
    fclose(instream);
    return (EXIT_SUCCESS);
}
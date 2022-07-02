#include "shell.h"
/**
 * get_input - get input from stream
 * basic and without arguments
 * 
 * Return : Always 0
 */
int get_input(void)
{
    ssize_t numchar;
    size_t len;
    char **lineptr = malloc(sizeof(char) * MAXLEN);
    FILE *instream = NULL;

    instream = fdopen(STDIN, "r");
    if (instream == NULL)
    {
        perror("Fdopen Error");
        return (EXIT_FAILURE);
    }

    while ((numchar = getline(lineptr, &len, instream)) != -1 
        && numchar != EOF)
    {
        printf("%s", *lineptr); 
        printf("%s", PROMPT);
    }

    free(lineptr);
    fclose(instream);
    return (EXIT_SUCCESS);
}
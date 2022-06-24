#include "main.h"
/**
 * main - strtok
 * 
 * Return : Always 0
 */
int main(int ac, char **av)
{
    size_t len = MAXLEN;
    ssize_t nchar;
    char **line;
    char *str_token; 
    char *delim = " ,;:_-\t";

    line = malloc(sizeof(char) * len);
    str_token = NULL;

    if (ac != 1)
        printf("Usage: %s :) No other arguments\n", *av);
    else
    {
        while ((nchar = getline(line, &len, stdin)) != -1 && nchar != EOF)
        { 
            while ((str_token = strtok(*line++, delim)) != NULL)
            {
                printf("%s\n", str_token);
            }
        }
    }
    free(str_token);
    free(line);
    free(av);
    free(stdin);
    return (0);
}
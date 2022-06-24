#include "main.h"
/**
 * main - getline
 * 
 * Return : Always 0
 */
int main(int ac, char **av)
{
    char **line = malloc(sizeof(char) * MAXLEN);
    ssize_t nchar = 0;
    size_t len = MAXLEN;

    if (ac != 1)
    {
        printf("Usage: %s :) No arguments needed\n", *av);
        return (-1);
    }
    else
    {
        printf("$ ");
        while ((nchar = getline(line, &len, stdin)) != -1 && nchar != EOF)
        {
            printf("%s", *line);
        }
    }
    free(line);
    return (0);
}
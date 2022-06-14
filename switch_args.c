#include "main.h"
/**
 * switch_args - get input with args from stream
 * simple version
 * 
 * Return : Always 0
 */
int switch_args(__attribute__((unused)) int ac, char **av)
{
    int i = 1;
    struct stat statbuf;

    if (stat(av[i], &statbuf) != 0)
    {
        perror("Stat Error");
        return(EXIT_FAILURE);
    }

    if(execve(av[i], av, NULL) == -1)
    {
        perror("Execution Error");
        return (EXIT_FAILURE);
    }
    /* printf("%s\n", *(av + i)); */
    return (EXIT_SUCCESS);
}
#include "shell.h"
/**
 * print_path - get input with path from stream
 * simple version
 * 
 * Return : Always 0
 */
int print_path(__attribute__((unused))int ac, char **av, __attribute__((unused))char **env)
{
    char *active_path = malloc(sizeof(char) * MAXLEN);

    if ((active_path = getenv(av[1])) == NULL)
    {
        perror("Get PATH Error");
        return (EXIT_FAILURE);
    }

    printf("%s\n", active_path);
    printf("%s", PROMPT);

    free(active_path);
    return (EXIT_SUCCESS);
}
#include "shell.h"
/**
 * print_env - get input with path from stream
 * simple version
 * 
 * Return : Always 0
 */
int print_env(__attribute__((unused))int ac, __attribute__((unused))char **av, char **env)
{
    if(execve(env[0], env, NULL) == -1)
    {
        perror("Execution Error");
        return (EXIT_FAILURE);
    }

    printf("%s\n", *env);
    printf("%s", PROMPT);

    return (EXIT_SUCCESS);
}
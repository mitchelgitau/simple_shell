#include "main.h"
/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av, char **env)
{
    unsigned int i;

    i = 0;
    while (env[i] != NULL)
    {
        printf("%s\n", env[i]);
        i++;
    }
    return (0);
}
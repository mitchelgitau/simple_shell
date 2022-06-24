#include "shell.h"
/**
 * main - check the code
 * @argc : arguments count
 * @argv : arguments array
 * 
 * Return: Always 0.
 */
int main (int argc, char **argv, char **env)
{
    cmd(argc, argv, env);
    return (0);
}
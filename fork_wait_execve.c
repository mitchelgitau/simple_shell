#include "main.h"
/**
 * main - fork + wait + execve 
 * 
 * Return : Always 0
 */
int main(void)
{
    int i = 0, status;
    pid_t parent, child;
    char *av[] = {"/bin/ls", "-l", "/tmp", NULL};

    parent = getpid();
    printf("(%u) : Parent\n", parent);

    for (; i < 5; i++)
    {
        child = fork();
        if (child == -1)
        {
            perror("Error giving birth");
            return (1);
        }
        if (child == 0)
        {
            sleep(1);
            if (execve(av[0], av, NULL) == -1)
            {
                perror("Error printing");
                return (1);
            }
        }
        else
        {
            wait(&status);
            printf("(%u) : Child\n", child);
        }
    }
    return (0);
}
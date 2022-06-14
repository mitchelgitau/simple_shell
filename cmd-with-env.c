#include "main.h"
/**
 * cmd - UNIX command line interpretor
 * @ac : arguments count
 * @av : arguments array
 * 
 * Return : Always 0
 */
int cmd(int ac, char **av, char **env)
{
    int wstate;
    pid_t parent_pid, child_pid;

    if (ac != 1)
    {
        printf("Usage Error: %s\n", av[0]);
        return (EXIT_FAILURE);
    }

    if(env[0] == NULL)
    {
        printf("Env Error: %s\n", env[0]);
        return (EXIT_FAILURE);
    }

    parent_pid = getpid();
    child_pid = fork();

    if (child_pid == -1)
    {
        perror("Child Error");
        return (EXIT_FAILURE);
    }

    if (child_pid == 0)
    {
        printf("(%u) A star is born !!\n", parent_pid);
        printf("%s", PROMPT);
        print_env(ac, av, env);
        /* get_env(); */
    }
    else
    {
        wait(&wstate);
        printf("(%u) died for our sins so we could live !!\n", child_pid);
        printf("(%u) has left the conversation !!\n", parent_pid);
    }
    return (EXIT_SUCCESS);
}
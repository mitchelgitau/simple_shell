#include "shell.h"
/**
 * cmd - UNIX command line interpretor
 * @ac : arguments count
 * @av : arguments array
 * @env : environment array
 * 
 * Return: 0 if successful; 1 otherwise
 */
int cmd(int ac, char **av, char **env)
{
	int wstate;
	pid_t parent_pid, child_pid;
	
	if (env[0] == NULL)
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
		switch_mode(ac, av, env);
	}
	else
	{
		wait(&wstate);
		printf("(%u) died for our sins so we could live !!\n", child_pid);
		printf("(%u) has left the conversation !!\n", parent_pid);
	}
	return (EXIT_SUCCESS);
}

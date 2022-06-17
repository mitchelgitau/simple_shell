#include "shell.h"
/**
 * switch_mode - get any input with args and env from program
 * @ac : arguments count
 * @av : argument array
 * @env : environment array
 *
 * Return : 0 if successful; 1 otherwise
 */
int switch_mode(int ac, char **av, char **env)
{
	int i = 1, a, e;

	if (ac > 1)
	{
		a = stat_exec(av, i);
		e = stat_exec(env, i);
		if (e != EXIT_SUCCESS)
		{
			if (a == STAT_FAILURE)
			{
				perror("ARGS Stat Error");
			}
			else if (a  == EXEC_FAILURE)
			{
				perror("ARGS Execution Error");
			}
		}
		else
		{
			if (a == STAT_FAILURE)
			{
				perror("ARGS Stat Error");
			}
			else if (a  == EXEC_FAILURE)
			{
				perror("ARGS Execution Error");
			}
		}
	}
	else
		fetch_token();
	return (EXIT_SUCCESS);
}

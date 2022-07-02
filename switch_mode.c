#include "shell.h"
/**
 * switch_mode - get any input with av and env from program
 * @ac : arguments count
 * @av : argument array
 * @env : environment array
 *
<<<<<<< HEAD
 * Return : 0 if successful; 1 otherwise
 */
int switch_mode(int ac, char **av, char **env)
{
	int i = 1, a, e;
=======
 * Return: 0 if successful; 1 otherwise
 */
int switch_mode(int ac, char **av, char **env)
{
	int i = 1, j = 0, a, e;
>>>>>>> nick

	if (ac > 1)
	{
		a = stat_exec(av, i);
<<<<<<< HEAD
		e = stat_exec(env, i);
=======
		e = stat_exec(env, j);

>>>>>>> nick
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
<<<<<<< HEAD
		fetch_token();
=======
    {
		if (fetch_token() == EXIT_FAILURE)
        {
				perror("Fetch Token Error");
				return (EXIT_FAILURE);
		}
    }
>>>>>>> nick
	return (EXIT_SUCCESS);
}

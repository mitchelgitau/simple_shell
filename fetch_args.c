#include "shell.h"
/**
 * fetch_args - get input with args, env, path, exit from stream
 * advanced version
 * @av : argument array
 * @env : environment array
 *
 * Return: Always 0
 */
int fetch_args(char **av, char **env)
{
	FILE *instream = NULL;
	int len = MAXLEN;
	char *working_dir = NULL, *dirbuf = NULL;

	if ((getenv(env[0])) == NULL)
	{
		perror("Get ENV Error");
		return (EXIT_FAILURE);
	}

	instream = fdopen(STDIN, "r");
	if (instream == NULL)
	{
		perror("Fdopen Error");
		return (EXIT_FAILURE);
	}

	working_dir = getcwd(dirbuf, len);
	if (working_dir == NULL)
	{
		perror("Get current working directory Error");
		return (EXIT_FAILURE);
	}

	if (av[1] == NULL)
		fetch_token(instream);
	
	if (execve(av[0], av, NULL) == -1)
	{
		perror("Execution Error");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

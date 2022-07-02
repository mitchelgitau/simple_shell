#include "shell.h"
/**
 * which_command - locate a command in path
 * @command : shorthand command string to search in path
 *
 * Return: 0 if successful; 1 otherwise
 */
int which_command(char *command)
{
	char **path_loc = NULL;
	char **token_paths = NULL;
	char *delim = ":=";
	char *path_env = "PATH";

	*path_loc = getenv(path_env);
    if (*path_loc == NULL)
	{
		perror("Get PATH Error");
		return (EXIT_FAILURE);
	}

	while ((*token_paths = strtok(*path_loc++, delim)) != NULL)
	{
		if ((search_paths(token_paths, command)) == EXIT_FAILURE)
		{
			perror("Search Paths Error");
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

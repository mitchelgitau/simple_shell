#include "shell.h"
/**
 * which_command - locate a command in path
<<<<<<< HEAD
 * @command : command string
 *
 * Return: command found ; 1 otherwise
=======
 * @command : shorthand command string to search in path
 *
 * Return: 0 if successful; 1 otherwise
>>>>>>> nick
 */
int which_command(char *command)
{
	char **path_loc = NULL;
<<<<<<< HEAD
	char *found_command = NULL;
	char *token_path = NULL;
	char *delim = ":=";
	char *path_env = "PATH";

	if ((*path_loc = getenv(path_env)) == NULL)
	{
		perror("Get PATH Error");
		exit(EXIT_FAILURE);
	}
	while ((token_path = strtok(*path_loc++, delim)) != NULL)
	{
		found_command = search_paths(token_path, command);
	}
	printf("%s\n", found_command);
	printf("%s", PROMPT);

	return (found_command);
=======
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
>>>>>>> nick
}

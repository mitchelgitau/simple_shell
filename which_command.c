#include "shell.h"
/**
 * which_command - locate a command in path
 * @command : command string
 *
 * Return: command found ; 1 otherwise
 */
char *which_command(char *command)
{
	char **path_loc = NULL;
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
}

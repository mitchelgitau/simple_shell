#include "shell.h"
/**
 * search_paths - search a directory path listing the command
 * @path_list : list of path directories
 * @command : shorthand command to search
 *
 * Return: 0 if successful; 1 otherwise
 */
int search_paths(char **path_list, char *command)
{
	int i = 0;

	while (path_list[i++] != NULL)
	{
		if ((_scandir(command, path_list[i])) == EXIT_FAILURE)
		{
			perror("Scandir Error");
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

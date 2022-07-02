#include "shell.h"
/**
 * _scandir - scan for match in directory with command
 * @command : shorthand command to search for
 * @dir : directory
 *
 * Return: 0 if successful; 1 otherwise
 */
int _scandir(char *command, char *dir)
{
	char **resolved_path = NULL;
	struct dirent *read_dir = NULL;
	DIR *open_dir = NULL;

	open_dir = opendir(dir);
	if (open_dir == NULL)
	{
		perror("Opendir Error");
		return (EXIT_FAILURE);
	}

	while ((read_dir = readdir(open_dir)) != NULL)
	{
		if (strcmp(read_dir->d_name, ".") == 0
				|| strcmp(read_dir->d_name, "..") == 0)
			continue;

		if (strcmp(read_dir->d_name, command) == 0)
		{
			*resolved_path = strcat(read_dir->d_name, command);
			if ((stat_exec(resolved_path, 0)) != EXIT_SUCCESS)
			{
				perror("Stat Error on resolved path");
				return (EXIT_FAILURE);
			}
		}
	}
	closedir(open_dir);
	return (EXIT_SUCCESS);
}

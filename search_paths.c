#include "shell.h"
/**
<<<<<<< HEAD
 * search_paths - locate a directory path with the command
 * @token_path : directory path
 * @command : command
 *
 * Return: command found ; 1 otherwise
=======
 * search_paths - search a directory path listing the command
 * @path_list : list of path directories
 * @command : shorthand command to search
 *
 * Return: 0 if successful; 1 otherwise
>>>>>>> nick
 */
int search_paths(char **path_list, char *command)
{
	int i = 0;

<<<<<<< HEAD
	if ((realpath(command, (char *)*command_dir)) == NULL)
	{
		perror("Realpath Error");
		exit(EXIT_FAILURE);
	}
	while (token_path[i] != '\0')
	{
		open_dir = opendir(&token_path[i]);
		if (open_dir == NULL)
		{
			perror("Opendir Error");
			exit(EXIT_FAILURE);
		}
		*read_dir = readdir(open_dir);
		if (*read_dir == NULL)
		{
			perror("Readdir Error");
			exit(EXIT_FAILURE);
		}
		scan_count = scandir(&token_path[i], scan_list, NULL, (int *)
				alphasort(read_dir, command_dir));
		if (scan_count == -1)
		{
			perror("Scandir Error");
			exit(EXIT_FAILURE);
		}
		if ((path_command = strstr((**scan_list)->d_name, command)) 
				!= NULL)
			break;
		closedir(open_dir);
		i++;
	}
	printf("%s\n", path_command);
	printf("%s", PROMPT);

	return (path_command);
=======
	while (path_list[i++] != NULL)
	{
		if ((_scandir(command, path_list[i])) == EXIT_FAILURE)
		{
			perror("Scandir Error");
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
>>>>>>> nick
}

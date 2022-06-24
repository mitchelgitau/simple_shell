#include "shell.h"
/**
 * search_paths - locate a directory path with the command
 * @token_path : directory path
 * @command : command
 * 
 * Return: command found ; 1 otherwise
 */
char *search_paths(char *token_path, char *command)
{
	int i = 0, scan_count;
	DIR *open_dir = NULL;
	const struct dirent **read_dir, **command_dir;
	struct dirent ***scan_list;
	char *path_command = NULL;

	if ((realpath(command, (char *)*command_dir)) == NULL)
    {
        perror("Realpath Error");
        exit (EXIT_FAILURE);
    }

	while(token_path[i] != '\0')
	{
		open_dir = opendir(&token_path[i]);
		if (open_dir == NULL)
		{
			perror("Opendir Error");
			exit (EXIT_FAILURE);
		}
		
		*read_dir = readdir(open_dir);
		if (*read_dir == NULL)
		{
			perror("Readdir Error");
			exit (EXIT_FAILURE);
		}

		scan_count = scandir(&token_path[i], scan_list, NULL, (int *)alphasort(read_dir, command_dir));
		if (scan_count == -1)
		{
			perror("Scandir Error");
			exit (EXIT_FAILURE);
		}

		if ((path_command = strstr((**scan_list)->d_name, command)) != NULL)
			break;
		closedir(open_dir);
		i++;
	}

    printf("%s\n", path_command);
    printf("%s", PROMPT);

	return(path_command);
}

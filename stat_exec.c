#include "shell.h"
/**
 * stat_exec - run stat and execve on str
 * @str : character string
<<<<<<< HEAD
 *
 * Return : 0 if successful;
 * 1 if stat fails;
=======
 * @i : position of first character
 *
 * Return: 0 if successful;
 * 1 if stat fails
>>>>>>> nick
 * 2 if execve fails
 */
int stat_exec(char **str, int i)
{
	struct stat statbuf;

	if (stat(str[i], &statbuf) != 0)
<<<<<<< HEAD
	{
		return (STAT_FAILURE);
	}
	if (execve(str[i], str, NULL) == -1)
	{
		return (EXEC_FAILURE);
	}
=======
		return (STAT_FAILURE);
	if (execve(str[i], str, NULL) == -1)
		return (EXEC_FAILURE);

>>>>>>> nick
	return (EXIT_SUCCESS);
}

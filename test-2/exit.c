#include "shell.h"

/**
 * exit_handle - handling exit built in
 * @token:...
 * @line:...
 *
 * Return: Nothing
 */
void exit_handle(char **token, char *line)
{
	int status = 0;

	if (token[1] == NULL || (!_strcmp(token[1], "0")))
	{
		free_token(token);
		free(line);
		exit(0);
	}
	status = _atoi(token[1]);
	if (status != 0)
	{
		free_token(token);
		free(line);
		exit(status);
	}
	else
	{
		_puts("exit:");
		_puts(u_tokns[1]);
		_puts("\n");
		exit(2);
	}


	frees_tokens(token);
	free(line);
	exit(EXIT_SUCCESS);
}

#include "shell.h"
/**
 * fetch_token - get token from getline
 * @instream : input stream
 *
 * Return: Always 0
 */
int fetch_token(FILE *instream)
{
	struct stat statbuf;
	int numchar;
	size_t len = MAXLEN;
	char **lineptr = NULL, **token_str = NULL, *delim = " ,;\t";
	char **absolute_token = NULL, *working_dir = NULL, *exit_str = "exit";

	while ((numchar = getline(lineptr, &len, instream)) != -1
			&& numchar != EOF)
	{
		while ((*token_str = strtok(*lineptr++, delim)) != NULL)
		{
			if (strncmp(*token_str, exit_str, strlen(exit_str)) == 0)
				_exit(EXIT_SUCCESS);

			if ((realpath(*token_str, *absolute_token)) == NULL)
			{
				perror("Realpath Error");
				return (EXIT_FAILURE);
			}

			printf("%s\n", absolute_token[0]);
			printf("%s", PROMPT);

			if (absolute_token[1] == NULL)
				strcat(*absolute_token, working_dir);

			if (stat(absolute_token[0], &statbuf) != 0)
			{
				perror("Stat Error");
				return (EXIT_FAILURE);
			}

			if (execve(absolute_token[0], absolute_token, NULL) == -1)
			{
				perror("Execution Error");
				return (EXIT_FAILURE);
			}
		}
	}
	return (EXIT_SUCCESS);
}

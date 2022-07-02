#include "shell.h"
/**
 * fetch_token - get tokens from stream
 *
 * Return: 0 if successful; 1 otherwise
 */
int fetch_token(void)
{
	FILE *instream = NULL;
	int numchar;
	size_t len = MAXLEN;
	char **lineptr = malloc(sizeof(char) * MAXLEN);
	char **token_str = malloc(sizeof(char) * MAXLEN);
	char *exit_str = "exit";
	char *delim = " ,;\t";

	instream = fdopen(STDIN, "r");
	if (instream == NULL)
	{
		perror("Fdopen Error");
		return (EXIT_FAILURE);
	}

	while ((numchar = getline(lineptr, &len, instream)) != -1
			&& numchar != EOF)
	{
		while ((*token_str = strtok(*lineptr++, delim)) != NULL)
		{
			if (strncmp(*token_str, exit_str, strlen(exit_str))
					== 0)
				_exit(EXIT_SUCCESS);

			if ((which_command(*token_str)) == EXIT_FAILURE)
			{
				perror("Which Error");
				return (EXIT_FAILURE);
			}
		}
		printf("%s", PROMPT);
	}
	free(lineptr);
	free(token_str);
	fclose(instream);
	return (EXIT_SUCCESS);
}

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
	size_t i = 0, len = MAXLEN;
	char **lineptr = malloc(sizeof(char) * MAXLEN);
	char **token_str = NULL;
	char **absolute_token = NULL;
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
			if (strncmp(*token_str, exit_str, strlen(exit_str)) == 0)
				_exit(EXIT_SUCCESS);

			*absolute_token = which_command(*token_str);

			printf("%s\n", absolute_token[0]);
			printf("%s", PROMPT);

			stat_exec(absolute_token, i);
		}
	}
	free(lineptr);
	fclose(instream);
	return (EXIT_SUCCESS);
}

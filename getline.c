#include "shell.h"
/**
 * _getline - gets a full line from input source s into d
 * @d : destination to store line of character stream
 * @lim : maximum size limit of character stream
 * @s : source of line of character stream
 *
 * Return: number of characters read
 */
ssize_t _getline(char **d, int *lim, FILE *s)
{
	ssize_t counter = 0;
	int ch;

	while (--lim > 0 && (ch = getchar()) != EOF && ch != '\n')
		*(d[counter++]) = ch;

	if (ch == '\n')
		*(d[counter++]) = ch;

	*(d[counter]) = '\0';
	return (counter);
}

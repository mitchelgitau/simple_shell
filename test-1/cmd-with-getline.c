#include "main.h"
/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int ac, char *av[])
{
    FILE *instream;
    char **readline = malloc(sizeof(char) *MAXLEN);
    size_t len = 0;
    ssize_t char_read;

    if (ac != 1) {
        fprintf(stderr, "Usage: %s <nothing>\n", av[0]);
        exit(EXIT_FAILURE);
    }

    instream = fdopen(0, "r");
    if (instream == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    while ((char_read = getline(readline, &len, instream)) != -1) 
    {
        
        if (execve(readline[0], readline, NULL) == -1)
        {
            perror("Execve");
            return (1);
        }
    }
    free(readline);
    fclose(instream);
    exit(EXIT_SUCCESS);
}
#include "main.h"
/**
 * main - ac and **av
 * 
 * Return : Always 0
 */
int main(int ac, char **av)
{
    int i;

    if (!ac)
        return (-1);

    if (!av)
        return (-1);

    i = 0;
    while (**(av + i) != '\0')
    {
        printf("%s\n", *(av + i));
        i++;
    }
    return (0);
}
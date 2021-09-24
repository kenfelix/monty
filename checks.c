#include "monty.h"

/**
 * is_alpha - checks if a string contains a letter
 * @str: the string to be checked
 * Return: 1 if true, else 0
 */
int is_alpha(char *str)
{
    if (str == NULL)
        return (1);
    
    while (*str)
    {
        if (*str < 48 || *str > 57)
            return (1);
        str++;
    }

    return (0);
}
#include "monty.h"

/**
 * check_string - verify if argument is alpha
 * @s: string passed to function
 * Return: integer
 */

int check_string(char *s)
{
	register int str_idx = 0;

	if (!s)
	{
		return (-1);
	}
	if (*s == '-')
	{
		s++;
	}
	while (s[str_idx])
	{
		if (s[str_idx] >= '0' && s[str_idx] <= '9')
		{
			str_idx++;
		}
		else
		{
			return (-1);
		}
	}
	return (1);
}

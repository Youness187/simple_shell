#include "main.h"
/**
 * lenstr - count the length of a string
 * @s: string
 * Return: length
*/
int lenstr(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

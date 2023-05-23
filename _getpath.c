#include "main.h"

/**
 * _getpath - Looking for the paths.
 * Return: the Full PATH From environ
 */
char *_getpath()
{
	char *key;
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		key = strtok(environ[i], "=");
		if (_strcmp("PATH", key) == 0)
			return (strtok(NULL, "\n"));
	}
	return (NULL);
}

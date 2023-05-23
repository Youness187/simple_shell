#include "main.h"

char *_getpath()
{
    char *key;
    int i;

    for (i = 0; environ[i] != NULL; i++)
    {
        key = strtok(environ[i], "=");
        if (strcmp("PATH", key) == 0)
            return (strtok(NULL, "\n"));
    }
    return (NULL);
}
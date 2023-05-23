#include "main.h"

void sh(list_path *list_head, char *a)
{
    pid_t pid = 0;
    size_t n = 0;
    char *buffer;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            print("$ ");
        pid = getline(&buffer, &n, stdin);
        if (pid == -1)
        {
            exit(0); 
        }
        execute(buffer, list_head, a);
    }
}

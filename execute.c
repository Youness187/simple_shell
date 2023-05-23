#include "main.h"

void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

void execute(char *command, list_path *list_head, char *ag)
{
    char **arg, *com;

    if (strcmp(command, "\n") == 0)
        return;

    arg = arguments(command);
    com = commandFonder(command, list_head);
    if (com != NULL)
    {
        pid_t pid;
        if (strcmp(com, "exit") == 0)
            exit(arg[1] != NULL ? atoi(arg[1]) : 0);

        pid = fork();
        if (pid == 0)
        {
            if (execve(com, arg, environ) == -1)
            {
                perror(command);
                exit(126);
            }
        }
        else
        {
            wait(NULL);
            free(com);
            ffree(arg);
        }
    }
    else
    {
        ffree(arg);
        print(ag);
        print(": ");
        print(command);
        print(": command not found\n");
    }
}

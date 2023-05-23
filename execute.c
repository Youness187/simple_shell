#include "main.h"
/**
 * ffree - freeing the two Dimensional array
 * @pp: the two Dimensional array
 */

void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}
/**
 * execute - Executing the command if it's available.
 * @command: the command
 * @list_head: linked list of system paths
 * @ag: file name
 */
void execute(char *command, list_path *list_head, char *ag)
{
	char **arg, *com;

	if (_strcmp(command, "\n") == 0)
		return;

	arg = arguments(command);
	com = commandFonder(command, list_head);
	if (com != NULL)
	{
		pid_t pid;

		if (_strcmp(com, "exit") == 0)
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

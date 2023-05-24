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
	int status;

	if (_strcmp(command, "\n") == 0)
		return;

	arg = arguments(command);
	com = commandFonder(arg[0], list_head);
	if (com != NULL)
	{
		pid_t pid;

		if (_strcmp(com, "exit") == 0)
			exit(0);

		pid = fork();
		if (pid == 0)
		{
			signal(SIGINT, SIG_DFL);
			if (execve(com, arg, environ) < 0)
			{
				perror(command);
				return;
			}
		}
		else
		{
			waitpid(pid, &status, WUNTRACED);
			if (com != arg[0])
				free(com);
			ffree(arg);
		}
	}
	else
	{
		ffree(arg);
		perror(ag);
	}
}

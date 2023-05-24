#include "main.h"
/**
 * arguments - handling the arguments
 * @buffer: the full command
 *
 * Return: 2D array
 */
char **arguments(char *buffer)
{
	char **arg;
	char *token;
	char *buffer_copy;
	int len_buffer = 0, i;
	unsigned long int len = lenstr(buffer);

	buffer_copy = malloc(sizeof(char) * len);
	if (buffer_copy == NULL)
	{
		return (NULL);
	}
	_strcpy(buffer_copy, buffer);
	token = strtok(buffer_copy, " \n\t\r\a\v");
	if (token == NULL)
	{
		free(buffer_copy);
		return (NULL);
	}
	for (len_buffer = 0; token; len_buffer++)
	{
		token = strtok(NULL, " \n\t\r\a\v");
	}
	free(buffer_copy);
	arg = malloc(sizeof(char *) * len_buffer + 1);

	if (arg == NULL)
	{
		return (NULL);
	}
	token = strtok(buffer, " \n\t\r\a\v");
	for (i = 0; token; i++)
	{
		arg[i] = malloc(sizeof(char) * lenstr(token) + 1);
		_strcpy(arg[i], token);
		_strcat(arg[i], "\0");
		token = strtok(NULL, " \n\t\r\a\v");
	}
	arg[i] = NULL;
	free(token);
	return (arg);
}

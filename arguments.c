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
	int len_buffer, i, len = lenstr(buffer);

	buffer_copy = malloc(sizeof(char) * len);
	_strcpy(buffer_copy, buffer);

	token = strtok(buffer_copy, " \n\t\r\a\v");
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

#include "main.h"

char *commandFonder(char *command, list_path *path)
{
    char *full_command, *token;
    list_path *h = path;
    struct stat st;
    if (stat(command, &st) == 0 || command == NULL){
        return (command);
    }
    if (strcmp(command, "exit") == 0)
        return ("exit");
    while (h != NULL)
    {
        token = h->dir;
        full_command = malloc((lenstr(token) + lenstr(command) + 2) * sizeof(char));
        if (full_command == NULL){
            return (NULL);
        }
        strcpy(full_command, token);
        strcat(full_command, "/");
        strcat(full_command, command);
        strcat(full_command, "\0");
        if (stat(full_command, &st) == 0){
            return (full_command);
        }
        free(full_command);
        h = h->next;
    }
    return (NULL);
}

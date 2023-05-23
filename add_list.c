#include "main.h"


list_path *add_node_end(list_path **head, char *n)
{
	list_path *new;
	list_path *old = *head;

	while (old != NULL && old->next != NULL)
		old = old->next;

	new = malloc(sizeof(list_path));
	if (new == NULL)
		return (NULL);

	new->dir = n;
	new->next = NULL;

	if (old == NULL)
	{
		*head = new;
		return (new);
	}
	else
		old->next = new;

	return (new);
}


int adding_path(list_path **head)
{
    char *key = NULL, *path = _getpath();
    int i = 0;

    if (path != NULL)
    {
        key = strtok(path, ":");
    }
    while (key)
    {
        add_node_end(head, key);
        i++;
        key = strtok(NULL, ":");
    }
    return (i);
}
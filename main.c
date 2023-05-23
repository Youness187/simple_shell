#include "main.h"

int main(int argc, char **argv)
{
    list_path *list_head = NULL;

    (void)argc;
    adding_path(&list_head);
    sh(list_head, argv[0]);
    return 0;
}

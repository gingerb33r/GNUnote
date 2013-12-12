#include <stdio.h>
#include "att.h"

void save_one()
{
    printf("Hello!\n");
}

void add_note(int note_num, const char *title, const char *text, NOTE *note, 
        void (*saveM)())
{
    (*saveM)();
    note->title = title;
    printf("%s\n", note->title);
}

int main(int argc, char **argv)
{
    printf("Freenote: The power of free thought.\n");
    printf("Initializing Freenote server...\n");
    return 0;
}

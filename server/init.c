#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

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
    MYSQL_INFO *info = malloc(sizeof(*info)); /*Allocated the amount of memory that can be accessed
                                                    here.*/
    info->IP = "192.168.1.235"; info->user = "YOLO"; 
    info->pass = "1"; info->DB = "test";
    printf("Freenote: The power of free thought.\n");
    printf("Initializing Freenote server...\n");
    MYSQL_CONNECT_DB(info);
    free(info);
    return 0;
}

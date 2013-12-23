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
    MYSQL *conn;
    MYSQL_INFO *info = malloc(sizeof(*info)); /*Allocated the amount of memory that can be accessed here.*/
    info->IP = "192.168.1.235"; info->user = "YOLO"; 
    info->pass = "1"; info->DB = "test";
    printf("Freenote: The power of free thought.\n");
    printf("Initializing Freenote server...\n");
    
    if((conn = MYSQL_CONNECT_DB(info)) == (MYSQL *) 0){
        printf("MySQL connection failed. Exiting.\n");
        return 1;
    };
    free(info);
    int c;
    while((c = getchar()) != EOF)
        ; //Do nothing loop, waits for a null terminator.
    printf("%d\n", EOF);
    EXIT_SERVER(conn);
    return 0;
}

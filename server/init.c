#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
    /*Initialization functions only. There shall be no processes defined in the main function, only executed.*/
    initscr();
    cbreak();
    int mainloop;
    printw("Freenote: The power of free thought.\n");
    printw("Initializing Freenote server...\n");
    refresh();
    if((mainloop = sql_loop()) == 1)
    {
        printw("Freenote exited with an error.\n The program will automatically shut down in 10 seconds.\n");
        refresh();
        sleep(10);
        getch();
        endwin();
        printf("Freenote exited with an error! Check the log file for more information.\n");
        return 1;
    } else {
        endwin();
        return 0;
    }
    return 0;
}

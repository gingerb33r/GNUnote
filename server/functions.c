#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "functions.h"

void INThandler(int sig)
{
    signal(sig, SIG_IGN);
    printw("Closing server...\n");
    refresh();
    sleep(5);
    endwin();
    exit(0);
}

MYSQL_INFO *CONNECTION_INIT()
{
    MYSQL_INFO *info = malloc(sizeof(*info)); /*Allocated the amount of memory that can be accessed here.*/
    info->IP = "192.168.1.235"; info->user = "YOLO"; 
    info->pass = "1"; info->DB = "test";
    return info;
}

int EXIT_SERVER(MYSQL *connection)
{
    mysql_close(connection);
    printw("MySQL session has now closed.\n");
    refresh();
    return KILL_SIGNAL;
}

MYSQL *MYSQL_CONNECT_DB(MYSQL_INFO *info)
{
    MYSQL *connection;
    const char *server = info->IP;
    const char *user = info->user;
    const char *password = info->pass;
    const char *database = info->DB;

    connection = mysql_init(NULL);

    if(!mysql_real_connect(connection, server, user, password, database, 0, NULL, 0)){
        printw("Error: %s\n", mysql_error(connection));
        MYSQL *f = KILL_SIGNAL;
        refresh();
        return f;
    }
    printw("Connected to MySQL server.\nTo exit, press CTRL + C.\n"); 
    return connection;
}

MYSQL_RES SEND_MYSQL_QUERY(MYSQL *conn)
{
    printw("SEND THE QUERY HERE.\n");
    refresh();
    MYSQL_RES a;
    return a;
}

int sql_loop() /*This is the main loop to be concerned with.*/
{
    MYSQL *conn;
    MYSQL_INFO *info = CONNECTION_INIT();
    if((conn = MYSQL_CONNECT_DB(info)) == (MYSQL *) 0){
        printw("MySQL connection failed. Exiting.\n");
        refresh();
        return 1;
    } else {
        int key;
        nodelay(stdscr,TRUE);
        signal(SIGINT, INThandler);
        while(1){
            if((key = getch()) == ERR) {
                if(mysql_ping(conn) == 1){
                    printw("Error!\n");
                    refresh();
                    
                    return 1;
                } 
            } else {
                if(key == EOF) break;
            }
        }
        free(info);
        EXIT_SERVER(conn);
        return 0;
    }
    return 0;
}

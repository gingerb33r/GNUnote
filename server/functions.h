#include "att.h"
#include <mysql/mysql.h>
#include <ncurses.h>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void INThandler(int sig);
MYSQL_INFO *CONNECTION_INIT();
MYSQL *MYSQL_CONNECT_DB(MYSQL_INFO *info); /*Sends to connect to server*/
int EXIT_SERVER(MYSQL *connection);
MYSQL_RES SEND_MYSQL_QUERY(MYSQL *conn);
int sql_loop();

#endif

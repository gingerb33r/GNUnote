#include "att.h"
#include <mysql/mysql.h>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void MYSQL_CONNECT_DB(MYSQL_INFO *info); /*Sends to connect to server*/
int EXIT_SERVER(MYSQL *connection);
#endif

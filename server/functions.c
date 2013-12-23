#include <stdio.h>
#include "functions.h"

int EXIT_SERVER(MYSQL *connection)
{
    mysql_close(connection);
    printf("MySQL session has now closed.\n");
    return 0;
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
        fprintf(stderr, "Error: %s\n", mysql_error(connection));
        MYSQL *f = 0;
        return f;
    }
    printf("Connected to MySQL server.\nTo exit, press CTRL + D.\n"); 
    return connection;
}


#ifndef ATT_H
#define ATT_H

enum signal_codes {
    KILL_SIGNAL
};

typedef struct user_info{
    const char *username; /*For example: gingerb33r*/
    const char *email; /*For example: interjection@gnu.com*/
    const char *password_unhashed; /*An unhashed/plaintext password; for example: "password".
                                     Hashed passwords are stored in the database, the DB will
                                     not store any plaintext password.*/
} USER;

typedef struct thought{ /*Structure of a note, information will be added to the DB.*/ 
    int note_num; /*Categorizes the note in order. This will be sent back to the user.*/
    const char *title; /*Title of the note; for example: "Tomorrow's work"*/
    const char *text; /*Contents of the note; for example: "Do something."*/
} NOTE;

typedef struct MySQL_Details{ /*Wiil be used in conjunction with MySQL linker. This is just for reference.*/
    const char *IP; /*For example: 127.0.0.1*/
    const char *user; /*The user connecting to the server.*/
    const char *pass; /*The password of the user connecting to the server.*/
    const char *DB; /*Database name, for example: wreckinskrubs*/
} MYSQL_INFO;

#endif

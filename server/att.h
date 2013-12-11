typedef struct user_info{
    const char *username;
    const char *email;
    const char *password_unhashed;
} USER;

typedef struct thought{ /*Structure of a note, information will be added to the DB.*/ 
    int note_num; /*Categorizes the note in order. This will be sent back to the user.*/
    const char *title; /**/
    const char *text;
} NOTE;

typedef struct MySQL_Details{ /*Wiil be used in conjunction with MySQL linker. This is just for reference.*/
    const char *IP; /*For example: 127.0.0.1*/
    const char *DB; /*Database name, for example: wreckinskrubs*/
} MYSQL_INFO;

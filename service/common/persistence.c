//
// Created by lei-long on 2020/12/23.
//

#include <stdio.h>
#include "../include/persistence.h"

static MYSQL *conn_prt;

void set_sql_handle(MYSQL* mysql){
    conn_prt = mysql;
}

MYSQL* get_sql_handle(){
    return conn_prt;
}

int mySQL_connect(const char *host ,const char *user ,const char *pass ,const char *database){

    MYSQL *mysql = mysql_init(NULL);
    if(mysql_real_connect(mysql,host,user,pass,database,0,NULL,0) == 0){
        return 0;
    }
    set_sql_handle(mysql);
    return 1;
}

void mySQL_close(){
    mysql_close(get_sql_handle());
}

MYSQL* get_sql_data(char* query){
    if (mysql_query(conn_prt, query) != 0){
        PERROR("mysql_query");
        return NULL;
    }
    return conn_prt;
}

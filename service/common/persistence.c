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

int mySQL_connect(const char *host , const char *user , const char *pwd , const char *database){

    conn_prt = mysql_init(NULL);
    if(mysql_real_connect(conn_prt, host, user, pwd, database, 0, NULL, 0) == 0){
        printf("数据库连接失败\n");
        return 0;
    }
    printf("数据库连接成功\n");
    return 1;
}

void mySQL_close(){
    mysql_close(get_sql_handle());
    printf("数据库断开连接\n");
}

MYSQL* get_sql_data(char* query){
    printf("query: %s\n", query);
    int ret = mysql_query(conn_prt, query);
    printf("ret = %d\n", ret);
    if (ret > 0){
        PERROR("数据库访问出错");
        return NULL;
    }
    return conn_prt;
}

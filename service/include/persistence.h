//
// Created by lei-long on 2020/12/23.
//

#ifndef CHAT_SYSTEM_PERSISTENCE_H
#define CHAT_SYSTEM_PERSISTENCE_H

#include "common.h"
#include <mysql/mysql.h>

#define BUFFER_SIZE 1024

void set_sql_handle(MYSQL* mysql);

MYSQL* get_sql_handle();

/*
 * 连接数据库
 */
int mySQL_connect(const char *host , const char *user , const char *pass , const char *database);

/*
 * 清理资源,关闭连接
 */
void mySQL_close();

MYSQL* get_sql_data(char* query);

#endif //CHAT_SYSTEM_PERSISTENCE_H

#ifndef _MYSQL_H
#define _MYSQL_H



/*
 * 连接数据库
 */
int mySQL_connect(const char *host , const char *user , const char *pass , const char *database);


/*
 * 清理资源,关闭连接
 */
void mySQL_close();


#endif

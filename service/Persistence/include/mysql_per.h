/*************************************************************************
	>    File Name: MySQL.h
	>       Author: fujie
	>         Mail: fujie.me@qq.com
	> Created Time: 2017年08月09日 星期三 08时53分10秒
 ************************************************************************/

#ifndef _MYSQL_H
#define _MYSQL_H


#include<mysql/mysql.h>

/*
 * 连接数据库
 */
int mySQL_connect(const char *host , const char *user , const char *pass , const char *database);


/*
 * 清理资源,关闭连接
 */
void mySQL_close();


#endif

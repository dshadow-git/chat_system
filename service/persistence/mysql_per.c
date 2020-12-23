
#include <stdio.h>
#include "include/mysql_per.h"

//MYSQL * mysql;

int mySQL_connect(const char *host ,const char *user ,const char *pass ,const char *database){
//    mysql = mysql_init(NULL);
//    if(mysql_real_connect(mysql,host,user,pass,database,0,NULL,0) == 0){
//        return 0;
//    }
    return 1;
}


void mySQL_close(){
//    mysql_close(mysql);
}

//
// Created by lei-long on 2020/12/23.
//

#include <stdio.h>
#include "main.h"
#include "controller/include/monitor.h"
#include "include/persistence.h"

int main(){
    mySQL_connect(MYSQL_HOST, MYSQL_USER, MYSQL_PWD, MYSQL_DATABASE);
    my_listen();
    mySQL_close();
}

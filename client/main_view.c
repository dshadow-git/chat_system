//
// Created by lei-long on 2020/12/22.
//

#include <stdio.h>
#include <unistd.h>
#include "main_view.h"
#include "service/include/connect_srv.h"
#include "view/include/home_view.h"

int main(){
    connect_create(SERVER_HOST , SERVER_PORT);
    home_init();
    connect_close();

}
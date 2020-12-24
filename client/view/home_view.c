//
// Created by lei-long on 2020/12/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "include/home_view.h"
#include "include/account_view.h"

static int mark;

void home_init(){
    create_lock_home();
    mark = 0;
    int choice;
    do{
        if(mark == 1){
            home_menu();
            mark = 0;
        }
        system("clear");
        printf(
                "==============================\n"
                " ****欢迎进入尘影牌聊天室****\n"
                "==============================\n");
        printf(
                "功能选项:\n"
                "\t1.登录\n"
                "\t2.注册\n"
                "\t3.退出\n"
                "请输入功能序号:"
        );
        scanf("%d" , &choice);
        ffflush();
        switch(choice){
            case 1:
                if (account_view_login()){
                    sem_wait(get_lock_home());
                }
                break;
            case 2:
                if (account_view_register()){
                    sem_wait(get_lock_home());
                }
                break;
            case 3:
                destroy_lock_home();
                return;
                break;
            default:
                break;
        }
    }while(1);
}

void home_menu(){
    char choice;
    do{
        system("clear");

        printf( "--------------------------------\n");
        printf( "1.选择好友|2.选择群聊|3.处理申请\n"
                "4.添加好友|5.创建群聊|6.注销登录\n");
        printf( "--------------------------------\n"
                "功能选择:");

        scanf("%c",&choice);
        if(choice == '\n') continue;
        ffflush();
        switch(choice){
            case '1':

                break;
            case '2':

                break;
            case '3':

                break;
            case '4':

                break;
            case '5':

                break;
            case '6':
                if (account_view_nu_login()){
                    sem_wait(get_lock_home());
                }
                break;
        }
    }while(choice != '6');
}

void set_home_mark(int m){
    mark = m;
}
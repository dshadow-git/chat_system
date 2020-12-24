//
// Created by lei-long on 2020/12/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "include/home_view.h"
#include "include/account_view.h"

void home_init(){
    int uid = 0;
    int rid;
    int choice;
    do{
        if(uid > 0){
            home_menu();
            uid = 0;
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
                uid = account_view_login();
                break;
            case 2:
                rid = account_view_register();
                break;
            case 3:
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
                account_view_nu_login();
                break;
        }
    }while(choice != '6');
}
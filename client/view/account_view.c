//
// Created by lei-long on 2020/12/22.
//

#include <stdio.h>
#include <string.h>
#include "include/account_view.h"
#include "include/home_view.h"
#include "../service/include/account_srv.h"

static int type = 0;

int account_view_login(){
    char id[USER_ID_SIZE] , pwd[USER_PWD_SIZE];
    printf("请输入账号:");
    scanf("%s", id);
    ffflush();
    printf("请输入密码:");
    scanf("%s",pwd);
    ffflush();
    type = 1;
    return account_srv_login(id, pwd);
}

int account_view_register(){
    char name[USER_NAME_SIZE] , password[USER_PWD_SIZE];
    int sex;
    printf("请输入要注册的用户名:");
    scanf("%s",name);
    ffflush();
    while(1){
        printf("请输入性别(男/女):");
        scanf("%s",password);//懒得再开数组,暂借一下
        ffflush();
        if(strcmp(password ,"男") == 0){
            sex = 1;
            break;
        }
        else if(strcmp(password ,"女") == 0){
            sex = 0;
            break;
        }
        else{
            printf("目前不存在的性别...\n");
        }
    }
    printf("请输入密码:");
    scanf("%s",password);
    ffflush();
    struct user user;
    strcpy(user.name, name);
    strcpy(user.pwd, password);
    user.sex = sex;
    type = 2;
    return account_srv_register(user);
}

int account_view_nu_login(){
    type = 3;
    return account_srv_un_login(get_user());
}

void account_view_success(){
    switch (type){
        case 1: printf("用户:%s登录成功\n", get_user().name);
            set_home_mark(1);
            break;
        case 2:
            printf("注册成功，恭喜你获得账号\n");
            printf("账号：%s\n", get_user().id);
            printf("昵称：%s\n", get_user().name);
            printf("接下来你可以使用账号：%s 和密码进行登录", get_user().id);
            set_home_mark(0);
            break;
    }
    type = 0;
    sem_post(get_lock_home());
}

void account_view_failed(char* buf){
    printf("%s\n", buf);
    type = 0;
    set_home_mark(0);
    sem_post(get_lock_home());
}

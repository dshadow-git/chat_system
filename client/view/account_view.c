//
// Created by lei-long on 2020/12/22.
//

#include <stdio.h>
#include <string.h>
#include "include/account_view.h"
#include "../service/include/account_srv.h"

int account_view_login(){
    char id[USER_ID_SIZE] , pwd[USER_PWD_SIZE];
    printf("请输入账号:");
    scanf("%s", id);
    ffflush();
    printf("请输入密码:");
    scanf("%s",pwd);
    ffflush();
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
    return account_srv_register(user);
}

void account_view_nu_login(){
    struct user user;
    strcpy(user.id, get_user_id());
    account_srv_un_login(user);
}

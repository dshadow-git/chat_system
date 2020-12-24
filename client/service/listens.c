//
// Created by lei-long on 2020/12/24.
//

#include <stdio.h>
#include <stdlib.h>
#include "include/listens.h"
#include "../view/include/account_view.h"

void listen_success(){
    struct user user;
    int ret = recv(get_sock_id(), (void*)&user, sizeof(user), 0);
    if (ret == -1){
        PERROR("recv");
        return;
    }
    if (ret < sizeof(user)){
        printf("数据出错\n");
        return;
    }
    printf("响应成功\n");
    set_user(user);
    account_view_success();
}

void listen_failed(int data_len) {
    printf("len:%d\n", data_len);
    struct general_msg *msg = (struct general_msg*) malloc(data_len);
    int ret = recv(get_sock_id(), (void*)msg, data_len, 0);
    printf("len:%d, ret:%d\n", data_len, ret);
    if (ret == -1){
        PERROR("recv");
        return;
    }
    if (ret < data_len){
        printf("数据出错\n");
        return;
    }
    printf("响应失败\n");
    account_view_failed(msg->data);
}

void listen_login(){

}
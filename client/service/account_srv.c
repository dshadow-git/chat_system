//
// Created by lei-long on 2020/12/22.
//

#include <stdio.h>
#include "include/account_srv.h"

int account_srv_login(char* id, char* pwd){
    int sock_id = get_sock_id();
    struct mutual mu;
    struct user user;

    strcpy(user.id, id);
    strcpy(user.pwd, pwd);

    mu.type = MY_MUTUAL_LOGIN;
    mu.data_len = sizeof(user);

    int ret;
    ret = send(sock_id, (void*)&mu, sizeof(mu), 0);
    if (ret == -1){
        printf("%s :\n", __func__);
        perror("send");
        return -1;
    }

    ret = send(sock_id, (void*)&user, sizeof(user), 0);
    if (ret == -1){
        printf("%s :\n", __func__);
        perror("send");
        return 0;
    }
    set_user_id(id);
    printf("登录成功!按任意键继续\n");
    getchar();
    return 1;
}

int account_srv_register(struct user user){
    int sock_id = get_sock_id();
    struct mutual mu;
    mu.type = MY_MUTUAL_REGISTER;
    mu.data_len = sizeof(user);
    int ret;
    ret = send(sock_id, (void*)&mu, sizeof(mu), 0);
    if (ret == -1){
        printf("%s :", __func__);
        perror("send");
        return -1;
    }

    ret = send(sock_id, (void*)&user, sizeof(user), 0);
    if (ret == -1){
        printf("%s :", __func__);
        perror("send");
        return 0;
    }

    printf("注册成功!按任意键继续\n");
    getchar();
    return 1;
}
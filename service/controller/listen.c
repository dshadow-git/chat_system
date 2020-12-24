//
// Created by lei-long on 2020/12/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/listen.h"

void listen_register(int client_id, struct mutual *mu) {
    struct user *user = (struct user*) malloc (sizeof(struct user));
    int ret = recv(client_id, (void*)user, sizeof(struct user), 0);
    if (ret == sizeof(struct user)){
        printf("recv: id:%s, name:%s, pwd:%s\n", user->id, user->name, user->pwd);
        mu->data = user;
    } else {
        PERROR("recv");
        listen_un_login(client_id, NULL);
    }
}

void listen_login(int client_id, struct mutual *mu) {
    struct user *user = (struct user*) malloc (sizeof(struct user));
    int ret = recv(client_id, (void*)user, sizeof(struct user), 0);
    if (ret == sizeof(struct user)){
        printf("recv: id:%s, pwd:%s\n", user->id, user->pwd);
        mu->data = user;
    } else {
        PERROR("recv");
    }
}

void listen_friend(int client_id, struct mutual *mu) {
    struct friend_msg *friendMsg = (struct friend_msg*) malloc (sizeof(struct friend_msg));;
    int ret = recv(client_id, (void*)friendMsg, sizeof(friendMsg), 0);
    if (ret == sizeof(friendMsg)){
        printf("type:%d, src:%s, dest:%s\n", friendMsg->type, friendMsg->src_user, friendMsg->dest_user);
        mu->data = &friendMsg;
    } else {
        PERROR("recv");
    }
}

void listen_group(int client_id, struct mutual *mu) {
    struct group_msg groupMsg;
    int ret = recv(client_id, (void*)&groupMsg, sizeof(groupMsg), 0);
    if (ret == sizeof(groupMsg)){
        mu->data = &groupMsg;
    } else {
        PERROR("recv");
    }
}

void listen_un_login(int client_id, struct mutual *mu) {
    struct user user;
    int ret = recv(client_id, (void*)&user, sizeof(user), 0);
    if (ret == sizeof(user)){
        printf("id:%s, pwd:%s\n", user.id, user.pwd);
        mu->data = &user;
    } else {
        PERROR("recv");
    }
}

void listen_close(int client_id){
    close(client_id);
}
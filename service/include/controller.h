//
// Created by lei-long on 2020/12/23.
//

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include "common.h"

#ifndef CHAT_SYSTEM_CONTROLLER_H
#define CHAT_SYSTEM_CONTROLLER_H

#define SOCK_LIST_SIZE 20
#define RESPONSE_SUCCESS 1
#define RESPONSE_FAILED 0
#define RESPONSE_LOGIN 2
#define RESPONSE_REGISTER 3
#define RESPONSE_FRIEND_DATA 5
#define RESPONSE_FRIEND_ADD 6
#define RESPONSE_GROUP_DATA 7
#define RESPONSE_GROUP_CREATE 8

struct sock{
    int flag;
    int sock_id;
    int user_id;
};

struct sock_queue{
    int len;
    int count;
    struct sock sock[SOCK_LIST_SIZE];
};

void sock_list_init();

void add_sock_id(char* user_id, int sock_id);

int get_sock_id(char* user_id);

void remove_sock_id(int sock_id);

void sock_list_close();

#endif //CHAT_SYSTEM_CONTROLLER_H

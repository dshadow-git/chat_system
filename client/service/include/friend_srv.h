//
// Created by lei-long on 2020/12/22.
//

#ifndef CHAT_SYSTEM_FRIEND_VIEW_H
#define CHAT_SYSTEM_FRIEND_H

#include "../../include/server.h"

struct friend{
    char uid[USER_ID_SIZE];
    char name[USER_NAME_SIZE];
    int sex;
    int is_vip;//是否是会员
    int is_follow;//是否为特别关心
    int is_online; //是否在线
    int new_msg_num; //未读消息数
    int state;
    struct friends *next;
};

struct friends{
    int num;
    struct friend* friend;
};

int friend_srv_add(char* f_id);

struct friends friend_srv_search(char* value);

struct friends friend_srv_find(char* f_id);

struct friends friend_srv_find_all();

#endif //CHAT_SYSTEM_FRIEND_VIEW_H

//
// Created by lei-long on 2020/12/22.
//

#ifndef CHAT_SYSTEM_SERVER_H
#define CHAT_SYSTEM_SERVER_H

#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "common.h"

#define RESPONSE_SUCCESS 1
#define RESPONSE_FAILED 0
#define RESPONSE_LOGIN 2
#define RESPONSE_REGISTER 3
#define RESPONSE_FRIEND_DATA 5
#define RESPONSE_FRIEND_ADD 6
#define RESPONSE_GROUP_DATA 7
#define RESPONSE_GROUP_CREATE 8

#endif //CHAT_SYSTEM_SERVER_H

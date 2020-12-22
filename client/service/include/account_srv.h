//
// Created by lei-long on 2020/12/22.
//

#ifndef CHAT_SYSTEM_ACCOUNT_SRV_H
#define CHAT_SYSTEM_ACCOUNT_SRV_H

#include "../../include/server.h"

int account_srv_login(char* id, char* pwd);

int account_srv_register(struct user user);

#endif //CHAT_SYSTEM_ACCOUNT_SRV_H

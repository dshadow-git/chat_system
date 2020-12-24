//
// Created by lei-long on 2020/12/22.
//

#include "../../include/controller.h"

#ifndef CHAT_SYSTEM_LISTEN_H
#define CHAT_SYSTEM_LISTEN_H

void listen_login(int client_id, struct mutual *mu);

void listen_register(int client_id, struct mutual *mu);

void listen_friend(int client_id, struct mutual *mu);

void listen_group(int client_id, struct mutual *mu);

void listen_un_login(int client_id, struct mutual *mu);

void listen_close(int client_id);

#endif //CHAT_SYSTEM_LISTEN_H

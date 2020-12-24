//
// Created by lei-long on 2020/12/22.
//

#ifndef CHAT_SYSTEM_CONNECT_SRV_H
#define CHAT_SYSTEM_CONNECT_SRV_H

#include "../../include/server.h"
#include "listens.h"

int connect_create(const char *host ,int port);

void connect_close();
#endif //CHAT_SYSTEM_CONNECT_SRV_H

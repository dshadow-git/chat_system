//
// Created by lei-long on 2020/12/22.
//

#ifndef CHAT_SYSTEM_VIEW_H
#define CHAT_SYSTEM_VIEW_H

#include "common.h"
#include <semaphore.h>
//清空输入缓冲区
void ffflush();

void create_lock_home();

sem_t* get_lock_home();

void destroy_lock_home();

#endif //CHAT_SYSTEM_VIEW_H

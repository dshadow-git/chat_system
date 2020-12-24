//
// Created by lei-long on 2020/12/23.
//

#ifndef CHAT_SYSTEM_ACCOUNT_CTL_H
#define CHAT_SYSTEM_ACCOUNT_CTL_H

#include "../../include/controller.h"

void account_ctl_to_user(struct user *user, int sock_id);

void account_ctl_to_mag(char *buf, int sock_id);

#endif //CHAT_SYSTEM_ACCOUNT_CTL_H

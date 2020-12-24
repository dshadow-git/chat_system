//
// Created by lei-long on 2020/12/23.
//

#ifndef CHAT_SYSTEM_ACCOUNT_SQL_H
#define CHAT_SYSTEM_ACCOUNT_SQL_H

#include "../../include/persistence.h"

void account_sql_login(struct user user, int sock_id);

void account_sql_register(struct user *user, int sock_id);

void account_sql_un_login(struct user user);

struct user account_sql_get_data(char* self_id);

#endif //CHAT_SYSTEM_ACCOUNT_SQL_H

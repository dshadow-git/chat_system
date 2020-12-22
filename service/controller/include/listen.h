//
// Created by lei-long on 2020/12/22.
//

#ifndef CHAT_SYSTEM_LISTEN_H
#define CHAT_SYSTEM_LISTEN_H

#define USER_ID_LEN 6
#define DATA_MAX_LEN 1024

struct mutual{
    int type;
    int data_len;
    char src_user[USER_ID_LEN];
    char dest_user[USER_ID_LEN];
    char send_time[20];
    void* data;
};

struct mutual_data{

};

void listen_login(int client_id);
void listen_register(int client_id);
void listen_data(int client_id);

#endif //CHAT_SYSTEM_LISTEN_H

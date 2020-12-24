//
// Created by lei-long on 2020/12/23.
//

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "../include/controller.h"

static struct sock_queue sock_list;
static pthread_mutex_t sock_mutex;

void sock_list_init(){
    sock_list.len = 0;
    sock_list.count = 0;
    pthread_mutex_init(&sock_mutex, NULL);
}

void add_sock_id(char* user_id, int sock_id){
    struct sock sock;
    sock.flag = 1;
    sock.sock_id = sock_id;
    int id = atoi(user_id);
    if (id == 0){
        PERROR("atoi");
        return;
    }
    sock.user_id = id;
    while (sock_list.count == SOCK_LIST_SIZE){}
    pthread_mutex_lock(&sock_mutex);
    if (sock_list.count == sock_list.len){
        sock_list.sock[sock_list.len++] = sock;
        sock_list.count++;
    } else {
        for (int i = 0; i < sock_list.len; ++i) {
            if (sock_list.sock[i].flag == 0){
                sock_list.sock[i] = sock;
                sock_list.count++;
            }
        }
    }
    pthread_mutex_unlock(&sock_mutex);


}

int get_sock_id(char* user_id){
    int id = atoi(user_id);
    if (id == 0){
        PERROR("atoi");
        return -1;
    }
    for (int i = 0; i < sock_list.len; ++i) {
        if (sock_list.sock[i].flag && sock_list.sock[i].user_id == id){
            return sock_list.sock[i].sock_id;
        }
    }
    return -1;
}

void remove_sock_id(int sock_id){
    for (int i = 0; i < sock_list.len; ++i) {
        if (sock_list.sock[i].flag && sock_list.sock[i].sock_id == sock_id){
            pthread_mutex_lock(&sock_mutex);
            sock_list.sock[i].flag = 0;
            sock_list.count--;
            if (i == sock_list.len) {
                sock_list.len--;
            }
            pthread_mutex_unlock(&sock_mutex);
        }
    }
}

void sock_list_close(){
    sock_list.len = 0;
    sock_list.count = 0;
    pthread_mutex_destroy(&sock_mutex);
}
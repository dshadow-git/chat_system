//
// Created by lei-long on 2020/12/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/common.h"

static int sock_id;

static char user_id[USER_ID_SIZE];

static struct user self_user;

void set_sock_id(int id){
    sock_id = id;
}

int get_sock_id(){
    return sock_id;
}

void set_user_id(char *id){
    memcpy(user_id, id, USER_ID_SIZE);
}

char* get_user_id(){

    char *id = (char*) malloc (USER_ID_SIZE * sizeof(char));
    memcpy(id, user_id, USER_ID_SIZE);
    return id;
}

void set_user(struct user user){
    self_user = user;
}

struct user get_user(){
    return self_user;
}
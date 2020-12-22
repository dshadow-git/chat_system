//
// Created by lei-long on 2020/12/22.
//

#include <stdio.h>

#include "../include/listen.h"

void listen_register(int client_id){
    printf("2 %d\n", client_id);

}

void listen_login(int client_id){
    printf("1 %d\n", client_id);
}

void listen_data(int client_id){
    printf("3 %d\n", client_id);
}
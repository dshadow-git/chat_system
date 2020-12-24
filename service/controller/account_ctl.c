//
// Created by lei-long on 2020/12/23.
//

#include <stdio.h>
#include <stdlib.h>
#include "include/account_ctl.h"

void account_ctl_to_user(struct user *user, int sock_id) {
    struct mutual mu;
    mu.type = RESPONSE_SUCCESS;
    mu.data = user;
    mu.data_len = sizeof(struct user);
    if (send(sock_id, (void*)&mu, sizeof(mu), 0) == -1){
        PERROR("send");
    }
    if (send(sock_id, (void*)user, sizeof(struct user), 0) == -1){
        PERROR("send");
    }
    printf("请求成功回应完成\n");
}

void account_ctl_to_msg(char *buf, int sock_id) {
    printf("%s\n", buf);
    struct mutual mu;
    mu.type = RESPONSE_FAILED;
    struct general_msg *msg = (struct general_msg*) malloc (sizeof(struct general_msg) + DATA_MAX_SIZE);
    msg->data_len = sprintf(msg->data, "%s", buf);
    mu.data_len = sizeof(struct general_msg) + msg->data_len;
    printf("mu: type: %d len: %d size %lu\n", mu.type, mu.data_len, sizeof(struct mutual));
    if (send(sock_id, (void*)&mu, sizeof(struct mutual), 0) == -1){
        PERROR("send");
    }
    if (send(sock_id, (void*)msg, mu.data_len, 0) == -1){
        PERROR("send");
    }
    printf("请求失败回应完成\n");
}
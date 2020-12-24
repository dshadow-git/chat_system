//
// Created by lei-long on 2020/12/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "include/connect_srv.h"

void *thread(void* arg){
    int sock_id = get_sock_id();

    while (1) {
        struct mutual *mu = (struct mutual *) malloc(sizeof(struct mutual));
        int ret = recv(sock_id, (void*)mu, sizeof(struct mutual), 0);
        if (ret <= 0){
            perror("recv");
            break;
        }
        printf("recv: ret: %d, type: %d, len:%d\n", ret, mu->type, mu->data_len);
        switch (mu->type) {
            case RESPONSE_SUCCESS:
                listen_success();
                break;
            case RESPONSE_FAILED:
                listen_failed(mu->data_len);
                break;
            case RESPONSE_LOGIN:
                listen_success();
                break;
            default:
                printf("未知数据类型\n");
        }
    }
    pthread_exit(0);
}

int connect_create(const char *host ,int port){
    int sock_fd;
    struct sockaddr_in clie_addr;
    pthread_t p_id;
    memset(&clie_addr ,0 ,sizeof(struct sockaddr_in));
    clie_addr.sin_family = AF_INET;
    clie_addr.sin_port = htons(port);
    clie_addr.sin_addr.s_addr = inet_addr(host);
    sock_fd = socket(AF_INET , SOCK_STREAM , 0);
    if(sock_fd < 0){
        perror("socket");
        exit(0);
    }
    if(connect(sock_fd , (struct sockaddr *)&clie_addr,sizeof(struct sockaddr_in)) < 0){
        printf("%s:%d:\n", __func__, __LINE__);
        perror("connect");
        exit(0);
    }
    set_sock_id(sock_fd);
    pthread_create(&p_id , NULL , thread , &sock_fd);
    return 1;
}

void connect_close(){
    close(get_sock_id());
}
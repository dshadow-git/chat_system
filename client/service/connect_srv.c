//
// Created by lei-long on 2020/12/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "include/connect_srv.h"

void *thread(void* arg){

}

int connect_create(const char *host ,int port){
    int sock_fd;
    struct sockaddr_in clie_addr;
    //char *out;
    pthread_t p_id;
    //   pthread_mutex_init(&mutex ,NULL);
    // pthread_cond_init(&cond ,NULL);
    memset(&clie_addr ,0 ,sizeof(struct sockaddr_in));
    clie_addr.sin_family = AF_INET;
    clie_addr.sin_port = htons(port);
    clie_addr.sin_addr.s_addr = inet_addr(host);
    sock_fd = socket(AF_INET , SOCK_STREAM , 0);
    if(sock_fd < 0){
        perror("socket");
        exit(0);
    }
    set_sock_id(sock_fd);
    if(connect(sock_fd , (struct sockaddr *)&clie_addr,sizeof(struct sockaddr_in)) < 0){
        printf("%s:%d:\n", __func__, __LINE__);
        perror("connect");
        exit(0);
    }
    pthread_create(&p_id , NULL , thread , NULL);
    //usleep(5000);
    //pthread_cond_signal(&cond);
    return 1;
}

void connect_close(){
    close(get_sock_id());
}
//
// Created by lei-long on 2020/12/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <pthread.h>
#include "../include/monitor.h"
#include "../include/listen.h"

void *listen_distribute(void* arg){
    int client_id = *(int*)arg;
    struct msg *mg = (struct msg*) malloc (sizeof(struct msg) + DATA_MAX_LEN);
    int ret = recv(client_id, mg, sizeof(struct msg), 0);
    if (ret == 0){
        perror("recv");
    }
    switch (mg->type){
        case REQUEST_LOGIN: listen_login(client_id);
            break;
        case REQUEST_REGISTER: listen_register(client_id);
            break;
        case REQUEST_DATA: listen_data(client_id);
            break;
    }
    close(client_id);
    pthread_exit(0);
}

int my_listen() {
    int sock_fd, new_fd; //监听套接字 连接套接字
    struct sockaddr_in server_addr; // 服务器的地址信息
    socklen_t sin_size;
    int yes = 1;
    int ret;
    int i;
    //建立sock_fd套接字
    if((sock_fd = socket(AF_INET, SOCK_STREAM, 0))==-1){
        perror("setsockopt");
        exit(1);
    }
    printf("sockect_fd = %d\n", sock_fd);
    //设置套接口的选项 SO_REUSEADDR 允许在同一个端口启动服务器的多个实例
    // setsockopt的第二个参数SOL SOCKET 指定系统中，解释选项的级别 普通套接字
    if(setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int))==-1){
        perror("setsockopt error \n");
        exit(1);
    }

    server_addr.sin_family = AF_INET; //主机字节序
    server_addr.sin_port = htons(MYPORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;//通配IP
    memset(server_addr.sin_zero,'\0',sizeof(server_addr.sin_zero));
    if(bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1){
        perror("bind error!\n");
        exit(1);
    }
    if(my_listen(sock_fd, MAXCLINE) == -1){
        perror("my_listen error!\n");
        exit(1);
    }

    pthread_t nit[MAXCLINE];

    while(1){
        struct sockaddr_in client_addr; // 客户端的地址信息
        int client_sock = accept(sock_fd, (struct sockaddr*)&client_addr, &sin_size);
        if (client_sock < 0) {
            perror("client_sock\n");
            return -1;
        }
        pthread_t tid;
        pthread_create(&tid, NULL, listen_distribute, (void*)&client_sock);

    }
}

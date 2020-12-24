//
// Created by lei-long on 2020/12/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include "include/monitor.h"
#include "include/listen.h"
#include "../persistence/include/account_sql.h"

void *listen_distribute(void* arg){
    int client_id = *(int*)arg;

    while (1) {
        struct mutual *mu = (struct mutual *) malloc(sizeof(struct mutual));
        int ret = recv(client_id, mu, sizeof(struct mutual), 0);
        if (ret <= 0){
            perror("recv");
            listen_close(client_id);
            break;
        }
        printf("type:%d, len:%d\n", mu->type, mu->data_len);
        switch (mu->type) {
            case REQUEST_MUTUAL_LOGIN:
                listen_login(client_id, mu);
                account_sql_login(*(struct user *) mu->data, client_id);
                break;
            case REQUEST_MUTUAL_REGISTER:
                listen_register(client_id, mu);
                account_sql_register(*(struct user *) mu->data, client_id);
                break;
            case REQUEST_MUTUAL_FRIEND:
                listen_friend(client_id, mu);
                break;
            case REQUEST_MUTUAL_GROUP:
                listen_group(client_id, mu);
                break;
            case REQUEST_MUTUAL_UN_LOGIN:
                listen_un_login(client_id, mu);
                account_sql_un_login(*(struct user *) mu->data);
                break;
            default:
                printf("未知数据类型\n");
        }
    }
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
        PERROR("stockpot");
        exit(1);
    }
    printf("socket_fd = %d\n", sock_fd);
    //设置套接口的选项 SO_REUSEADDR 允许在同一个端口启动服务器的多个实例
    // setsockopt的第二个参数SOL SOCKET 指定系统中，解释选项的级别 普通套接字
    if(setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int))==-1){
        PERROR("setstockpot");
        exit(1);
    }

    server_addr.sin_family = AF_INET; //主机字节序
    server_addr.sin_port = htons(MYPORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;//通配IP
    memset(server_addr.sin_zero,'\0',sizeof(server_addr.sin_zero));
    if(bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1){
        PERROR("bind");
        exit(1);
    }
    if(listen(sock_fd, MAXCLINE) == -1){
        PERROR("listen");
        exit(1);
    }

    pthread_t nit[MAXCLINE];
    int c_nit = 0;
    while(1){
        struct sockaddr_in client_addr; // 客户端的地址信息
        int client_sock = accept(sock_fd, (struct sockaddr*)&client_addr, &sin_size);
        if (client_sock < 0) {
            PERROR("accept");
            return -1;
        }
        pthread_create(&nit[c_nit], NULL, listen_distribute, (void*)&client_sock);
        c_nit++;
    }
}

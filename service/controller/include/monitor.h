//
// Created by lei-long on 2020/12/22.
//

#ifndef CHAT_SYSTEM_MONITOR_H
#define CHAT_SYSTEM_MONITOR_H

#define MYPORT 2315 //连接时使用的端口
#define MAXCLINE 20 //连接队列中的个数
#define REQUEST_LOGIN 1
#define REQUEST_REGISTER 2
#define REQUEST_DATA 3

struct msg{
    int type;
    int data_len;
    char data[0];
};

int my_listen();

#endif //CHAT_SYSTEM_MONITOR_H

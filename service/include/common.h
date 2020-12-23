//
// Created by lei-long on 2020/12/23.
//

#ifndef CHAT_SYSTEM_COMMON_H
#define CHAT_SYSTEM_COMMON_H

#define USER_ID_SIZE 7
#define GROUP_ID_SIZE 6
#define USER_NAME_SIZE 11
#define GROUP_NAME_SIZE 20
#define USER_PWD_SIZE 12
#define DATA_MAX_SIZE 1024
#define FILE_NAME_MAX_SIZE 24
#define REQUEST_MUTUAL_LOGIN 1
#define REQUEST_MUTUAL_REGISTER 2
#define REQUEST_MUTUAL_FRIEND 3
#define REQUEST_MUTUAL_GROUP 4
#define REQUEST_MUTUAL_UN_LOGIN 5
#define REQUEST_MSG_FILE 11
#define REQUEST_MSG_CONTENT 12

#define PERROR(error) \
    printf("%s:%s:%d\n", __FILE__, __func__, __LINE__); \
    perror(error)

struct mutual{
    int type;
    int data_len;
    void* data;
};

/**
 * 好友消息
 */
struct friend_msg{
    int type;
    int data_len;
    char src_user[USER_ID_SIZE];
    char dest_user[USER_ID_SIZE];
    char send_time[20];
    void* data;
};

/**
 * 群聊消息
 */
struct group_msg{
    int type;
    int data_len;
    char group_id[GROUP_ID_SIZE];
    char user_id[USER_ID_SIZE];
    char send_time[20];
    void* data;
};

/**
 * 提示消息
 */
struct general_msg{
    int data_len;
    char data[0];
};

/**
 * 文件消息
 */
struct file_msg{
    int file_len;
    int data_len;
    char filename[0];
    char data[0];
};

struct user{
    int sex;
    int status;
    char id[USER_ID_SIZE];
    char name[USER_NAME_SIZE];
    char pwd[USER_PWD_SIZE];
};

#endif //CHAT_SYSTEM_COMMON_H

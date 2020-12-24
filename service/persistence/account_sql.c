//
// Created by lei-long on 2020/12/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/account_sql.h"

struct user sql_to_user(MYSQL* mysql){
    struct user user;
    MYSQL_RES *res = mysql_use_result(mysql);
    MYSQL_ROW row;
    if ((row = mysql_fetch_row(res)) != NULL) {
        strcpy(user.id, row[0]);
        strcpy(user.name, row[1]);
        user.sex = atoi(row[2]);
        user.status = atoi(row[3]);
        strcpy(user.pwd, row[4]);
    }
    return user;
}

int sql_to_int(MYSQL* mysql){
    int temp = 0;
    MYSQL_RES *res = mysql_use_result(mysql);
    MYSQL_ROW row;
    if ((row = mysql_fetch_row(res)) != NULL) {
        temp = atoi(row[0]);
    }
    return temp;
}

void account_sql_login(struct user user, int sock_id) {
    char buf[BUFFER_SIZE];
    sprintf(buf, "select * from user where id = \'%s\'", user.id);
    MYSQL* mysql = get_sql_data(buf);
    if (mysql == NULL){
        account_ctl_to_mag("该账号不存在", sock_id);
        return;
    }
    struct user new_user = sql_to_user(mysql);
    if (strcpy(user.pwd, new_user.pwd) != 0){
        account_ctl_to_mag("密码错误", sock_id);
        return;
    }
    memset(new_user.pwd, 0, USER_PWD_SIZE);
    sprintf(buf, "update user set status = 1 where id = \'%s\'", new_user.id);
    get_sql_data(buf);
    sprintf(buf, "登录成功");
    add_sock_id(new_user.id, sock_id);
    account_ctl_to_user(&new_user, sock_id);
}

void account_sql_register(struct user user, int sock_id) {
    char buf[BUFFER_SIZE];
    sprintf(buf, "select count(*) from user");
    int count = sql_to_int(get_sql_data(buf));
    sprintf(buf, "1%05d", count);
    memcpy(user.id, buf, USER_ID_SIZE-1);
    user.id[USER_ID_SIZE-1] = '\0';
    sprintf(buf, "insert into user(id, name, sex, pwd) values(\'%s\', \'%s\', %d, \'%s\')",
            user.id, user.name, user.sex, user.pwd);
    if (get_sql_data(buf) == NULL){
        account_ctl_to_mag("注册账号失败", sock_id);
        return;
    }
    sprintf(buf, "注册账号成功");
    memset(user.pwd, 0, USER_PWD_SIZE);
    account_ctl_to_user(&user, sock_id);
}

void account_sql_un_login(struct user user){
    char buf[BUFFER_SIZE];
    sprintf(buf, "update user set status = 0 where id = \'%s\'", user.id);
    if (!get_sql_data(buf)){
        account_ctl_to_mag("退出登录失败", get_sock_id(user.id));
        return;
    }
    account_ctl_to_user(&user, get_sock_id(user.id));
}

struct user account_sql_get_data(char* self_id){
    struct user user;

    return user;
}
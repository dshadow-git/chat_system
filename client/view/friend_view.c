//
// Created by lei-long on 2020/12/22.
//

#include <stdio.h>
#include "../service/include/friend_srv.h"
#include "include/friend_view.h"

static struct friends self_friends;

void friend_view_show(struct friends fs) {
    char *sex[2] = {"\e[35m♀\e[0m","\e[36m♂\e[0m"};
    struct friend *f = fs.friend;
    while(f){
        printf("账号：%s 昵称：%s\t 性别：%s\n", f->uid, f->name, sex[f->sex]);
    }
}

void friend_view_shows(){

}

void friend_view_add(){
    char fname[30];
    printf("请输入待查找的账号或者昵称:");
    scanf("%s",fname);
    ffflush();
    struct friends friends = friend_srv_search(fname);
    if (friends.num == 0){
        printf("没有 %s 的账号信息\n", fname);
        return;
    }
    printf("查找结果如下：\n");
    friend_view_show(friends);
    printf("请输入需要添加好友的账号");
    scanf("%s",fname);
    friend_srv_add(fname);
}

void friend_view_remove(){

}
//
// Created by lei-long on 2020/12/22.
//

#include <stdio.h>
#include "../include/view.h"

static sem_t home_sem;

//清空输入缓冲区
void ffflush(){
    char ch;
    while((ch=getchar())!='\n' && ch!=EOF){}
}

void create_lock_home(){
    sem_init(&home_sem, 0, 0);
}

sem_t* get_lock_home(){
    return &home_sem;
}

void destroy_lock_home(){
    sem_destroy(&home_sem);
}
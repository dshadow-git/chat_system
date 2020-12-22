//
// Created by lei-long on 2020/12/22.
//

#include <stdio.h>
#include "../include/view.h"

//清空输入缓冲区
void ffflush(){
    char ch;
    while((ch=getchar())!='\n' && ch!=EOF){}
}
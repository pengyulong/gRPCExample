/*
 * test.cc
 * Copyright (C) 2018 app <app@VM_127_30_centos>
 *
 */

//#include "test.h"

#include <iostream>
#include <thread>
#include <string>
using namespace std;
void print_id(int id){
    printf("hello,world,id:%d \n",id);
}
int main()
{
    //Test test;
    thread thread_array[10];
    for(int i = 0;i<10;i++)
        thread_array[i] = thread(print_id,i);
    for (int j = 0;j<10;j++)
        thread_array[j].join();
    return 0;
}




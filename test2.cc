/*
 * test2.cc
 * Copyright (C) 2018 app <app@VM_127_30_centos>
 *
 */

//#include "test2.h"

#include <thread>

#include <iostream>
using namespace std;

class Test{
    public:
        Test(){}
        Test(string name){
            message = name;
        }
        void print_id(int id)
        {
            printf("message:%s,id:%d \n",message.c_str(),id);
        }
    private:
        string message;
};


int main(){
    const int thread_num = 10;
    thread thread_array[thread_num];
    for(int i = 0;i<thread_num;++i)
        thread_array[i]=thread(&Test::print_id,Test("hello,world"),i);
    for(int j = 0;j<thread_num;++j)
        thread_array[j].join();

}



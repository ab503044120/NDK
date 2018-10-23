//
// Created by xiucheng yin on 2018/10/22.
//

#ifndef LSN6_SAFEQUEUE_H
#define LSN6_SAFEQUEUE_H
#include <iostream>

#include <queue>
#include <pthread.h>
using namespace std;


template <typename T>
class SafeQueue{
public:
    SafeQueue(){
        pthread_mutex_init(&mutex, 0);
        pthread_cond_init(&cond, 0);
    };
    ~SafeQueue(){
        pthread_mutex_destroy(&mutex);
        pthread_cond_destroy(&cond);
    };

    void push(T t){
        pthread_mutex_lock(&mutex);
        q.push(t);
        //由系统唤醒一个线程
        pthread_cond_signal(&cond);
        //广播通知所有等待线程
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
    }


    void pop(T& t){
        pthread_mutex_lock(&mutex);
        while (q.empty()){
            //挂起，让CPU休息
            pthread_cond_wait(&cond, &mutex);
        }

        t = q.front();
        q.pop();

        pthread_mutex_unlock(&mutex);
    }

private:
    std::queue<T> q;
    pthread_mutex_t mutex;
    //条件变量
    pthread_cond_t cond;

};
#endif //LSN6_SAFEQUEUE_H

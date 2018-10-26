//
// Created by xiucheng yin on 2018/10/26.
//

#ifndef TINAPLAYER_SAFE_QUEUE_H
#define TINAPLAYER_SAFE_QUEUE_H

#include <queue>
#include <pthread.h>

using namespace std;

template<typename T>

class SafeQueue {

    //定义一个函数指针
    typedef void(*RelaseCallback)(T &);

public:
    SafeQueue() {
        pthread_mutex_init(&mutex, 0);
        pthread_cond_init(&cond, 0);
    }

    ~SafeQueue() {
        pthread_mutex_destroy(&mutex);
        pthread_cond_destroy(&cond);
    }

    void push(T value) {
        pthread_mutex_lock(&mutex);
        q.push(value);
        //通知
        pthread_mutex_unlock(&mutex);
    }

    int pop(T &value) {
        int ret = 0;
        pthread_mutex_lock(&mutex);
        while (q.empty()) {
            //没有数据就等待
            pthread_cond_wait(&cond, &mutex);
        }
        if (!q.empty()) {
            value = q.front();
            q.pop();
            ret = 1;
        }
        pthread_mutex_unlock(&mutex);
        return ret;
    }

    void clear() {
        pthread_mutex_lock(&mutex);
        uint32_t size = q.size();
        for (int i = 0; i < size; ++i) {
            //取出队首的变量
            T value = q.front();

            //释放value
            if (relaseCallback){
                relaseCallback(value);
            }

            q.pop();
        }
        pthread_mutex_unlock(&mutex);
    }

    void setRelaseCallback(RelaseCallback relaseCallback){
        this->relaseCallback = relaseCallback;
    }

private:
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    queue<T> q;
    RelaseCallback relaseCallback;
};

#endif //TINAPLAYER_SAFE_QUEUE_H

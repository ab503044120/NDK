#include <iostream>

#include <thread>
#include <pthread.h>

using namespace std;

void task(int i) {
    cout << "线程：" << i << endl;
}

void *pthread_task(void *args) {

    int i = *static_cast<int *>(args);
    cout << "线程参数：" << i << endl;
    return 0;
}

#include <queue>

pthread_mutex_t mutex1;
queue<int> q;

void *queue_task(void *args) {
    pthread_mutex_lock(&mutex1);
    if (!q.empty()) {
        printf("获取队列数据：%d\n", q.front());
        q.pop();
    } else {
        printf("未获取数据\n");
    }
    pthread_mutex_unlock(&mutex1);
    return 0;
}

int main() {
    pthread_mutex_init(&mutex1, 0);
    for (size_t i = 0; i < 5; ++i) {
        q.push(i);
    }

    pthread_t pids[10];

    for (int j = 0; j < 10; ++j) {
        pthread_create(&pids[0], 0, queue_task, 0);
    }
    pthread_mutex_destroy(&mutex1);
    return 0;
}

int main2() {
    //posix
    //线程属性
    pthread_attr_t attr;
    //传递指针的指针
    pthread_attr_init(&attr);

    //设置是否为分离线程
    // PTHREAD_CREATE_DETACHED 分离
    //PTHREAD_CREATE_JOINABLE 非分离
    //默认为非分离线程
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    //调度策略与优先级
    pthread_attr_setschedpolicy(&attr, SCHED_FIFO);

    //设置优先级
    //获得对应策略的最小、最大优先级
    int max = sched_get_priority_max(SCHED_FIFO);
    int min = sched_get_priority_min(SCHED_FIFO);
    sched_param param;
    param.sched_priority = max;

    int r = pthread_attr_setschedparam(&attr, &param);

    cout << "优先级返回值r：" << r << endl;

    pthread_t pid;
    int i = 100;
    //多参数：结构体、class

    pthread_create(&pid, &attr, pthread_task, &i);

    pthread_join(pid, 0);

    pthread_attr_destroy(&attr);

    cout << "线程执行完毕" << endl;
    return 0;
}

#include <iostream>

#include <thread>
#include <pthread.h>
#include "SafeQueue.h"
#include "Ptr.h"

using namespace std;

class A{
public:
    ~A(){
        cout << "释放A" << endl;
    }
};

void testPtr() {
    A *a1 = new A;
    A *a2 = new A;

    //shared_a 处于栈当中
    Ptr<A> shared_a(a1); // a 引用计数:1
    //先创建了一个对象 变量是shared_b
    // a2 野生对象(没有智能指针指向a2了 )
    Ptr<A> shared_b(a2);  // 1
    //再将 shared_b 变量 重新赋值
    shared_b = shared_a;
    //出方法 shared_a 与 shared_b 会被回收
    //delete a2;
}

//智能指针
int main(){
    //c++ 11 st1 两种类型智能指针
    testPtr();

    vector<int> v;
//    decltype(v);
//    vector<int>::iterator it = v.begin();
//    for(auto i: v){
//        cout <<
//    }
    auto it = v.begin();
    return 0;
}

SafeQueue<int> sq;
void * get(void *){
    while (1){
        int i;
        //如果没有数据就卡在这里
        sq.pop(i);
        cout << "取出数据：" << i << endl;
    }
    return 0;
}


void * put(void *){
    while (1){
        int i;
        //将用户输入 给i保存
        cin >> i;
        sq.push(i);
    }
}

int main4(){
    pthread_t pid1, pid2;
    pthread_create(&pid1, 0, get, 0);
    pthread_create(&pid2, 0, put, 0);
    pthread_join(pid1, 0);
    return 0;
}

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

int main3() {
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

//
// Created by xiucheng yin on 2018/10/22.
//

#include "lsn5.h"
#include <iostream>

#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

class Type{
public:
    int i;
    Type(int i):i(i){};
};

vector<int> vec;

void testVec(){
    vec.push_back(1);
    vec.push_back(2);

    vec.clear();//占用的内存大小没有释放
    //swap 替换
    vector<int>().swap(vec);
    cout << "testVec:" << vec.capacity() << endl;
}

struct  type_less
{
    bool operator()(const Type& __x, const Type& __y) const
    {return __x.i < __y.i;}
};

struct  type_greater
{
    bool operator()(const Type& __x, const Type& __y) const
    {return __x.i > __y.i;}
};



int main(){

    testVec();
    //容器 stl：标准库模板
    //序列式 与 关联式

    //序列式容器：元素排列顺序与元素本身无关，由添加顺序决定的
    //vector、list、dequeue、 queue、stack、priorityQueue

    vector<int> vec_1;
    vector<int> vec_2(1);

    //6个元素值都是1
    vector<int> vec_3(6, 1);
    vector<int> vec_4(vec_3);

    //增加函数
    vec_1.push_back(10);
    vec_1.push_back(20);

    vec_1.pop_back();

    //通过下标来获取元素
    cout << "通过下标来获得元素：" << vec_1[0] << endl;

    vec_1.front();
    vec_1.back();

    vec_1.clear();
    vec_1.erase(vec_1.begin(), vec_1.end());//擦除

    cout << "vec_1 的容量大小：" << vec_1.capacity() << endl;

    queue<int> q;
    //加入队列
    q.push(1);
    q.push(2);

    //弹出队列
    q.pop();


    stack<int> s;
    s.push(1);
    s.push(2);

    s.pop();

    //优先级队列
    priority_queue<int> pq;
    pq.push(2);
    pq.push(1);
    pq.push(3);


    pq.top();
    cout << "默认优先级队列，队首：" << pq.top() << endl;

    priority_queue<int, vector<int>, less<int> > pq1;
    //less: 最大的元素在前面

    priority_queue<int, vector<int>, greater<int> > pq2;
    //greater: 最小的在前面


    //不知道如何给 Type排序
    priority_queue<Type, vector<Type>, type_less> pq_type;
    pq_type.push(Type(2));
    pq_type.push(Type(1));
    pq_type.push(Type(3));


    priority_queue<Type, vector<Type>, type_greater> pq_type2;
    pq_type2.push(Type(2));
    pq_type2.push(Type(1));
    pq_type2.push(Type(3));

    cout << "默认优先级队列，队首：" << pq_type2.top().i << endl;


    //关联式容器
    //通过一个关键字 保存和访问 元素的 map  set
    //set 集合 元素不可重复

    set<int> set1 = {1, 2, 3, 4};
    pair<set<int>::iterator, bool> _pair = set1.insert(5);
    set1.insert(1);

    set1.erase(1);
    cout << "set里面有：" << set1.size() << endl;


    //使用迭代器
    //指向容器中第0个元素
    vector<int> vec_5;
    vec_5.push_back(10);
    vec_5.push_back(20);
    //迭代器 行为和指针 是个模板类
    vector<int>::iterator it = vec_5.begin();
    // 指向容器中 最后一个的下一个元素
    // vs 编译器 cl.exe 有问题 ，g++没问题
    // g++ lsn5_example.cpp xxx.exe
    for (; it < vec_5.end(); )
    {
        if (*it == 10) {
            // windows vs 需要再给it重新赋值
            it = vec_5.erase(it);
        }
        else {
            it++;
        }
    }
    it = vec_5.begin();
    for (; it < vec_5.end(); ++it)
    {
        cout << "vec_5删除后有:" << *it << endl;
    }


    //map
    map<int, string> map1;
    map<int, string> map2 = {{1, "A"}, {2, "B"}};
    map2.insert({3, "C"});

    map2[3] = "D";


    //红黑树






    return 0;
}


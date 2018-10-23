//
// Created by xiucheng yin on 2018/10/23.
//
#ifndef LSN6_PTR_H
#define LSN6_PTR_H
using  namespace std;

template <typename T>
class Ptr{
public:
    Ptr(){
        count = new int(1);
        t = nullptr;
    }
    Ptr(T *t){
        count = new int(1);
        this->t = t;

    }
    ~Ptr(){
        //引用计数 -1
        --(*count);
        if (*count == 0){
            if (t != nullptr){
                delete t;
                t = nullptr;
            }
            delete count;
            count = nullptr;
        }

    }

    Ptr(const Ptr<T> &p){
        cout << "拷贝" << endl;
        //指向一个新的对象
        ++(*p.count);
        t = p.t;
        count = p.count;

    }

    Ptr<T>& operator=(const Ptr<T> &p){
        ++(*p.count);
        if (--(*count) == 0){
            if (t){
                delete t;
                count = nullptr;
            }
        }
        t = p.t;
        count = p.count;
        return *this;
    }

private:
    int *count; //引用计数
    T *t;
};

#endif //LSN6_PTR_H

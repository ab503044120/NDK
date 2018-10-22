#include <iostream>

struct Student{
    int i;
    short j;
}s1, s2;

typedef struct {
    int i;
    short j;
} Student1;

using namespace std;

namespace A{
    void test(){

    }
}

int ii;

int main() {
    std::cout << "Hello, World!" << std::endl;

    ii = 11;
    int ii = 10;

    cout << ii << endl;
    cout << ::ii << endl;

    //3、字符串
    //c 使用 Null \0 结尾的一个字符数组
    char str1[6] = {'h', 'e', 'l', 'l', '\0'};

    //默认加 \0
    char  *str2 = "hello";


    //域名控制
    return 0;
}
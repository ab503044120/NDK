#include <iostream>
#include <stdarg.h>

void test();

void add(char *b, ...){
    va_list list;
    va_start(list, 0);
}


//void (*p)(char*)函数
//void 返回值

void say(void (*p)(char*), char *msg){
    p(msg);
}

void println(char* msg){
    printf("println:%s\n", msg);
}

typedef void(*Func)(char*);

typedef void(*Success)(char*);

typedef void(*Faliue)(char*);

int main() {
    std::cout << "Hello, World!" << std::endl;


    Func fun = println;
    say(fun, "Tina");


    void (*p)(char*) = println;
    say(p, "hello");


    int i1 = 10;
    //& 取地址符
    int *p1 = &i1;
    // %#x 0xxxxx
    printf("i1 地址：%#x\n", &i1);
    printf("p1 值：%#x\n", p1);

    //解引用： 解析 地址 的值
    printf("p1 指向地址的值：%d\n", *p1);

    p1++;
    printf("p1 指向地址的值：%d\n", *p1);


    int array1[] = {11, 22, 33, 44};
    int *array_p1 = array1;
    for (size_t i = 0; i < 4; ++i) {
        printf("数组中的元素：%d\n", *(array1 + i));

    }

    //数组的指针
    int array2[2][3] = {{11, 22, 33},
                       {44, 55, 66}};
    //数组指针 int[3]
    int (*array_pa)[3] = array2;

    //访问 55
    printf( "%d/n", *(*(array2 + 1) + 1));


    char temp[] = "hello";
    //不能修改char对应的地址的值，指针p2的值是可以变的
    const char *p2 = temp;
    char const *p3 = temp;

    p2 = "Tina";

    char * const p4 = temp;
    p4[0] = 'a';

    const char * const p5 = temp;
    char const * const p6 = temp;


    //多级指针
    int i2 = 10;
    //
    int *p7 = &i2;

    int **p8 = &p7;


    //函数必须在适用之前声明
    test();
    //函数传参
        //1. 值传递

        //2. 引用传递


    return 0;
}

void test() {

}
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;

    int i = 10;
    long j = 10;

    long int j1;//对应java的 int
    long long j2;//对应java的long

    printf("%lu\n", sizeof(j));

    if(1){
        printf("true\n");
    }

    int32_t k;
    int64_t  z;//8个字节

    int a[10];
    int a1[] = {1,2,3,4,5};


    char str[100];
    for (size_t l = 0; l < 3 ; ++l) {
        sprintf(str, "/yinxiucheng/De");
        printf("%s", str);

    }


    int array[10];//栈区
    char c[1 * 1024 * 1024];

    //在
    int *jp = (int *)malloc(1 * 1024 * 1024);
    size_t k_size = 1 * 1024 * 1024;

    // 讲 jp指向的内存初始化 为0， 长度为K
    memset(jp, 0, k_size);

    free(jp);
    jp = 0;
    system("pause");


    int *i2 = (int *)calloc(10, sizeof(int));



    return 0;
}
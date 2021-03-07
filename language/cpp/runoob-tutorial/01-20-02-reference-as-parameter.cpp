//C++ 把引用作为参数
#include <iostream>
#include <cstdio>
using namespace std;

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

int main()
{
    int a = 100, b = 200;
    printf("before swap:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    swap(a, b);
    printf("\nafter swap:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    return 0;
}
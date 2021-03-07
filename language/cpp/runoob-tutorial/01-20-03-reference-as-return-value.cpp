// C++ 把引用作为返回值
#include <iostream>
#include <cstdio>
using namespace std;

int val[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int &setVal(int i)
{
    return val[i];
}
int main()
{
    printf("value before set:\n");
    for (int i = 0; i <= 9; i++)
    {
        printf("%d ", val[i]);
    }
    puts("");
    setVal(2) = 12;
    setVal(5) = 15;
    printf("\nvalue after set:\n");
    for (int i = 0; i <= 9; i++)
    {
        printf("%d ", val[i]);
    }
    puts("");
    return 0;
}
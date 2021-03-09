#include <iostream>
#include <cstdio>
using namespace std;
inline int Max(int x, int y)
{
    return x > y ? x : y;
}
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", Max(a, b));
    return 0;
}
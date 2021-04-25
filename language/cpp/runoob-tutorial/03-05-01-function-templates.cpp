#include <iostream>
#include <cstdio>
using namespace std;
template <typename T>
T const &Max(T const &a, T const &b)
{
    return a > b ? a : b;
}
int main()
{
    int a = 10, b = 12;
    printf("%d\n", Max(a, b));
    double c = 1.2, d = 1.3;
    printf("%lf\n", Max(c, d));
    return 0;
}
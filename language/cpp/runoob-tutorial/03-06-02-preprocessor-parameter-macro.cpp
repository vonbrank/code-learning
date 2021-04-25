#include <iostream>
#include <cstdio>
using namespace std;
#define MAX(a, b) (a > b ? a : b)
int main()
{
    int x = 10, y = 12;
    printf("%d", MAX(x, y));
    return 0;
}
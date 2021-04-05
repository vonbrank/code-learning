#include <iostream>
#include <cstdio>
#include "WinRandom.h"
#include <algorithm>
using namespace std;

int a[30];

int main()
{
    WinRandom R;
    //用 R.randInt() 来返回一个随机的 int

    int n = 30;
    printf("%d\n", n);
    for (int i = 1; i <= n; i++)
    {
        a[i] = R.randInt() % 26;
        a[i] = a[i] < 0 ? -a[i] : a[i];
        // printf("%d ", a[i]);
        printf("%c", 'a' + a[i]);
        // printf("%d ", A[i].data);
        // printf("%d ", R.randInt());
    }
    return 0;
}
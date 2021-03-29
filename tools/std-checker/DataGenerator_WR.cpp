#include <iostream>
#include <cstdio>
#include "WinRandom.h"
#include <algorithm>
using namespace std;

struct Node
{
    int data, loc;
    bool operator<(const Node &b) const
    {
        return data < b.data;
    }
} A[100];

int main()
{
    WinRandom R;
    //用 R.randInt() 来返回一个随机的 int

    int n = 10;
    for (int i = 1; i <= n; i++)
    {
        A[i] = (Node){R.randInt(), i};
        // printf("%d ", A[i].data);
        // printf("%d ", R.randInt());
    }
    sort(A + 1, A + n + 1);
    puts("");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", A[i].loc);
    }
    return 0;
}
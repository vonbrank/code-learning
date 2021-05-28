#include <iostream>
#include <cstdio>
#include "WinRandom.h"
#include <algorithm>
using namespace std;
const int maxn = 10000;

int main()
{
    WinRandom R;
    //用 R.randInt() 来返回一个随机的 int
    printf("%d %d", R.randInt() % maxn * (R.randInt() % 2 == 0 ? 1 : -1), R.randInt() % maxn * (R.randInt() % 2 == 0 ? 1 : -1));

    return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;
#define CONCAT(x, y, z) x##y##z
int main()
{
    int xyz = 100;
    printf("%d", CONCAT(x, y, z));
    return 0;
}
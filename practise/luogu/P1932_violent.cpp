#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 10050;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d\n", a + b);
    printf("%d\n", a - b);
    printf("%d\n", a * b);
    printf("%d\n", a / b);
    printf("%d\n", a % b);
    // printf("%d", a % b);
    return 0;
}
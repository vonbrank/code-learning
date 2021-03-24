#include <iostream>
#include <cstdio>
using namespace std;
long long gcd(long long a, long long b)
{
    if (a % b)
        return gcd(b, a % b);
    else
        return b;
}
int main()
{
    long long a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld", gcd(a, b));
    return 0;
}
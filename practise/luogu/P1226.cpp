#include <iostream>
#include <cstdio>
using namespace std;
long long b, p, k;
long long quick_pow(long long base, long long exp, long long mod)
{
    if (mod == 1)
        return 0;
    if (exp == 0)
        return 1;
    long long ans = 1;
    while (exp)
    {
        if (exp & 1)
        {
            ans *= base;
            ans %= mod;
        }
        base = base * base;
        base %= mod;
        exp >>= 1;
    }
    return ans;
}
int main()
{
    scanf("%lld %lld %lld", &b, &p, &k);
    printf("%lld^%lld mod %lld=%lld", b, p, k, quick_pow(b, p, k));
    return 0;
}
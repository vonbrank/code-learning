#include <iostream>
#include <cstdio>
using namespace std;
long long n, m, a, x, y;
int main()
{
    scanf("%lld %lld %lld", &n, &m, &a);
    x = n / a;
    y = m / a;
    if(n % a != 0) x++;
    if(m % a != 0) y++;
    printf("%lld", x * y);
    return 0;
}
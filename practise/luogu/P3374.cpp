#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 500500;
int n, m;
long long c[maxn];
int lowbit(int x)
{
    return x & -x;
}
void add(int x, long long k)
{
    while (x <= n)
    {
        c[x] += k;
        x += lowbit(x);
    }
}
long long query(int x, int y)
{
    long long ans1 = 0, ans2 = 0;
    x--;
    while (x >= 1)
    {
        ans1 += c[x];
        x -= lowbit(x);
    }
    while (y >= 1)
    {
        ans2 += c[y];
        y -= lowbit(y);
    }
    return ans2 - ans1;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        long long x;
        scanf("%lld", &x);
        add(i, x);
    }
    for (int i = 1; i <= m; i++)
    {
        int op, x, k;
        scanf("%d %d %d", &op, &x, &k);
        if (op == 1)
        {
            add(x, (long long)k);
        }
        if (op == 2)
        {
            printf("%lld\n", query(x, k));
        }
    }
    return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 100500;
const int mod = 1e9 + 7;
int n, ans;
int a[maxn], f[5050][5050], sum[maxn];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    sum[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        sum[i] = sum[i - 2] + a[i];
        sum[i] %= mod;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int l, r, f1, f2;
            l = i % 2 == 1 ? i : i + 1;
            r = j % 2 == 1 ? j : j - 1;
            f1 = sum[r] - sum[l - 2];
            l = i % 2 == 0 ? i : i + 1;
            r = j % 2 == 0 ? j : j - 1;
            f2 = sum[r] - sum[l - 2];
            ans += max(f1, f2);
            ans %= mod;
        }
    }
    if (ans < 0)
        ans += mod;
    printf("%d", ans);
    return 0;
}
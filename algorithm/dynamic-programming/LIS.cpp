#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 100500;
int n;
int a[maxn], dp[maxn], dp2[maxn], ans, ans2;
int main()
{
    while (scanf("%d", &a[++n]) != EOF)
    {
        dp[n] = dp2[n] = 1;
    }
    n--;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
        ans = max(ans, dp[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[i] <= a[j] && dp2[i] < dp2[j] + 1)
                dp2[i] = dp2[j] + 1;
        }
        ans2 = max(ans2, dp2[i]);
    }
    printf("%d\n%d", ans2, ans);
    return 0;
}
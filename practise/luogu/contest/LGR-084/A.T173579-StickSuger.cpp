#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1000500;
int n, ans_i, ans_j;
char s[maxn];
int a[maxn], maxr[maxn];
int main()
{
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
        a[i] = s[i] - 'a' + 1;
    maxr[n] = a[n];
    for (int i = n - 1; i >= 1; i--)
    {
        maxr[i] = max(maxr[i + 1], a[i]);
        // printf("%c ", 'a' + maxr[i] - 1);
    }

    // puts("");

    for (int i = 1; i <= n - 1; i++)
    {

        if (a[i] < maxr[i + 1])
        {
            ans_i = i;
            // break;
        }
        // if (i == n - 1 && a[i] < a[i + 1])
        // {
        //     printf("%d %d", i, i + 1);
        //     return 0;
        // }
    }
    if (ans_i == 0)
    {
        printf("-1");
        return 0;
    }
    for (int i = n; i > ans_i; i--)
    {
        if (a[i] > a[ans_i])
        {
            ans_j = i;
            break;
        }
    }
    printf("%d %d", ans_i, ans_j);
    return 0;
}
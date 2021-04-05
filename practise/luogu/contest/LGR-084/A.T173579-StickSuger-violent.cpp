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

    for (int i = n; i >= 1; i--)
    {
        for (int j = n; j >= i; j--)
        {
            if (i == j)
                continue;
            if (a[i] < a[j])
            {
                printf("%d %d", i, j);
                return 0;
            }
        }
    }
    printf("-1");
    return 0;
}
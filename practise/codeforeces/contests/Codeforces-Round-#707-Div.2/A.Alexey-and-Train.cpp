#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 10050;
int t, n;
int a[maxn], b[maxn], tm[maxn], c[maxn], d[maxn];
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d %d", &a[i], &b[i]);
        }
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &tm[i]);
        }
        // printf("debug:\n");
        for(int i=1; i<=n; i++)
        {
            c[i] = d[i-1] + a[i] - b[i-1] + tm[i];
            d[i] = c[i] + ceil((b[i] - a[i])/2.0) >= b[i] ? c[i] + ceil((b[i] - a[i])/2.0) : b[i];
            // printf("%d %d\n", c[i], d[i]);
        }
        printf("%d\n", c[n]);
    }
    return 0;
}
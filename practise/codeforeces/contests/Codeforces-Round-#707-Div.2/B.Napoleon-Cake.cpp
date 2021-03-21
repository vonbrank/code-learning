#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 200500;
int t, n;
int a[maxn];
bool vis[maxn];

void debug(int x)
{
    printf("debug_%d:\n", x);
    for(int i=1; i<=n; i++)
    {
        printf("%d ", vis[i]);
    }
    puts("");
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        memset(vis, 0, sizeof(vis));
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &a[i]);
        }
        for(int i=n; i>=1; i--)
        {
            int j = max(1, i - a[i] + 1);
            if(!vis[j])
            {
                while (j <= i)
                {
                    if(vis[j]) break;
                    vis[j] = true;
                    j++;
                }
            }
            // debug(i);
        }
        for(int i=1; i<=n; i++)
        {
            printf("%d ", vis[i]);
        }
        puts("");
    }
    
    return 0;
}
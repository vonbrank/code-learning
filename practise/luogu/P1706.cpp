#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 20;
int n;
int now[maxn];
bool vis[maxn];
void dfs(int depth)
{
    if(depth > n)
    {
        for(int i=1; i<=n; i++)
        {
            printf("%5d", now[i]);
        }
        puts("");
        return;
    }
    for(int i=1; i<=n; i++)
    {
        if(vis[i]) continue;
        vis[i] = true;
        now[depth] = i;
        dfs(depth + 1);
        vis[i] = false;
    }
}
int main()
{
    scanf("%d", &n);
    dfs(1);
    return 0;
}
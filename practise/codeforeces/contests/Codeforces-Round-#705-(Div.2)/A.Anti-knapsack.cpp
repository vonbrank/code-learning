#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int now, val, cnt;
bool vis[10000], used[10000];
int num[10000];

void dfs2(int depth)
{
    if(depth > cnt)
    {
        if(val <= now) vis[val] = true;
        return;
    }
    for(int i=0; i<=1; i++)
    {
        if(i) val += num[depth];
        dfs2(depth + 1);
        if(i) val -= num[depth];
    }
}

void dfs(int depth)
{
    if(depth > now)
    {
        memset(vis, 0, sizeof(vis));
        dfs2(1);
        if(!vis[now])
        {
            for(int i=1; i<=cnt; i++)
            {
                printf("%d ", num[i]);
            }
            puts("");
        }
        return;
    }
    for(int i=0; i<=1; i++)
    {
        used[depth] = i;
        if(used[depth]) num[++cnt] = depth;
        dfs(depth + 1);
        if(used[depth]) --cnt;
    }
}

void check()
{
    

    int max = 0;
    dfs(1);
    // for(int i=1; i<=9999; i++)
    // {
    //     if(vis[i]) printf("%d ", i);
    // }
    puts("");
}

int main()
{
    for(int i=1; i<=15; i++)
    {
        now = i;
        printf("%d:\n", i);
        check();
    }
    return 0;
}
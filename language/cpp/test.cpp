#include <iostream>
#include <cstdio>
using namespace std;
int n;
bool used[100];
int now[100];
void dfs(int depth)
{
    if(depth > n)
    {
        for(int i=1; i<=n; i++)
        {
            printf("%d ", now[i]);
        }
        puts("");
        return;
    }
    for(int i=1; i<=n; i++)
    {
        if(used[i]) continue;
        used[i] = true;
        now[depth] = i;
        dfs(depth + 1);
        used[i] = false;
    }
}
int main()
{
    scanf("%d", &n);
    dfs(1);
    return 0;
}
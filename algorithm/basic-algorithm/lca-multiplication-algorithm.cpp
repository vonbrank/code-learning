#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 500500;
const int maxlog = 20;
int n, m, s, cnt;
int head[maxn], fa[maxn][25], depth[maxn];
struct Node
{
    int to, next;
} G[maxn * 2];
void addedge(int u, int v)
{
    ++cnt;
    G[cnt].to = v;
    G[cnt].next = head[u];
    head[u] = cnt;
}
void dfs(int u)
{
    depth[u] = depth[fa[u][0]] + 1;
    for (int i = head[u]; i; i = G[i].next)
    {
        int v = G[i].to;
        if (v == fa[u][0])
            continue;
        fa[v][0] = u;
        dfs(v);
    }
}
int lca(int x, int y)
{
    if (depth[x] < depth[y])
        swap(x, y);
    for (int i = maxlog; i >= 0; i--)
    {
        if (depth[fa[x][i]] >= depth[y])
            x = fa[x][i];
    }
    if (x == y)
        return x;
    for (int i = maxlog; i >= 0; i--)
    {
        if (fa[x][i] == fa[y][i])
            continue;
        x = fa[x][i];
        y = fa[y][i];
    }
    return fa[x][0];
}

void debug()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 4; j++)
        {
            printf("%d ", fa[i][j]);
        }
        puts("");
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        addedge(x, y);
        addedge(y, x);
    }
    dfs(s);

    for (int j = 1; j <= maxlog; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
        }
    }

    // debug();

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}
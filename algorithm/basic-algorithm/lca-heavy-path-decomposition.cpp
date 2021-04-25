#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 500500;
int n, m, s, cnt;
int head[maxn], depth[maxn], size[maxn], son[maxn], top[maxn], fa[maxn];
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
void dfs1(int u)
{
    size[u] = 1;
    depth[u] = depth[fa[u]] + 1;
    for (int i = head[u]; i; i = G[i].next)
    {
        int v = G[i].to;
        if (v == fa[u])
            continue;
        fa[v] = u;
        dfs1(v);
        size[u] += size[v];
        if (size[v] > size[son[u]])
            son[u] = v;
    }
}
void dfs2(int u)
{
    if (son[fa[u]] == u)
        top[u] = top[fa[u]];
    else
        top[u] = u;
    for (int i = head[u]; i; i = G[i].next)
    {
        int v = G[i].to;
        if (v == fa[u])
            continue;
        dfs2(v);
    }
}
int lca(int x, int y)
{
    while (top[x] != top[y])
    {
        if (depth[top[x]] < depth[top[y]])
            swap(x, y);
        x = fa[top[x]];
    }
    return depth[x] < depth[y] ? x : y;
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
    dfs1(s);
    dfs2(s);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 500500;
const int maxlog = 20;
int n, m, s, cnt;
int head[maxn], fa[maxn], ans[maxn];
bool vis[maxn];
vector<int> query_list[maxn], query_id[maxn];
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
int getfa(int x)
{
    return fa[x] == x ? x : fa[x] = getfa(fa[x]);
}
void tarjan(int u)
{
    vis[u] = true;
    for (int i = head[u]; i; i = G[i].next)
    {
        int v = G[i].to;
        if (vis[v])
            continue;
        tarjan(v);
        fa[v] = u;
    }

    // printf("-------\n%d:\n", u);

    for (int i = 0; i < query_list[u].size(); i++)
    {
        int v = query_list[u][i];
        if (!vis[v] || ans[query_id[u][i]])
            continue;

        ans[query_id[u][i]] = getfa(v);
        // printf("%d %d: %d\n", u, v, ans[query_list[u][i]]);
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
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        query_list[a].push_back(b);
        query_list[b].push_back(a);
        query_id[a].push_back(i);
        query_id[b].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    tarjan(s);
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}
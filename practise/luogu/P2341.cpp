#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 100500;
int n, m, scc, cc, top, cnt;
int head[maxn], dfn[maxn], low[maxn], belong[maxn], stk[maxn], ans[maxn];
bool instk[maxn];
struct Node
{
    int to, next;
} G[maxn];
void addedge(int u, int v)
{
    ++cc;
    G[cc].to = v;
    G[cc].next = head[u];
    head[u] = cc;
}
void tarjan(int u)
{
    ++cnt;
    dfn[u] = low[u] = cnt;
    stk[++top] = u;
    instk[u] = true;
    for (int i = head[u]; i; i = G[i].next)
    {
        int v = G[i].to;
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (instk[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u])
    {
        ++scc;
        int v;
        do
        {
            v = stk[top--];
            belong[v] = scc;
            instk[v] = false;
            ans[scc] = max(ans[scc], v);
        } while (u != v);
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addedge(u, v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (dfn[i])
            continue;
        tarjan(i);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", ans[belong[i]]);
    }
    return 0;
}
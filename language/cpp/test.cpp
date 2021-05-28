#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1050;
int n, cc, tot, top, scc, st, end;
int head[maxn], dfn[maxn], low[maxn], stk[maxn], belong[maxn];
bool instk[maxn];
struct Node
{
    int to, next, from;
} edge[maxn * maxn];
void addedge(int u, int v)
{
    ++cc;
    edge[cc].from = u;
    edge[cc].to = v;
    edge[cc].next = head[u];
    head[u] = cc;
}
void tarjan(int u)
{
    low[u] = dfn[u] = ++tot;
    stk[++top] = u;
    instk[u] = true;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
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
        } while (v != u);
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int to;
        scanf("%d", &to);
        while (to != 0)
        {
            addedge(i, to);
            scanf("%d", &to);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
            tarjan(i);
    }
    return 0;
}
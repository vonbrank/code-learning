#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100500;
const int INF = 2147483647;
int n, m, s, cnt;
int head[maxn];
long long dis[maxn];
bool vis[maxn];
struct Edge
{
    int to, next, w;
} G[maxn * 5];
void addedge(int u, int v, int w)
{
    ++cnt;
    G[cnt].to = v;
    G[cnt].w = w;
    G[cnt].next = head[u];
    head[u] = cnt;
}
void dijkstra_naive(int s)
{
    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    dis[s] = 0;
    for (int i = 1; i <= n; i++)
    {
        int k;
        long long mn = INF;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && dis[j] < mn)
            {
                mn = dis[j];
                k = j;
            }
        }
        vis[k] = true;
        for (int j = head[k]; j; j = G[j].next)
        {
            int v = G[j].to;
            int w = G[j].w;
            if (vis[v])
                continue;
            if (dis[v] > dis[k] + w)
                dis[v] = dis[k] + w;
        }
    }
}
int main()
{
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addedge(u, v, w);
    }
    dijkstra_naive(s);
    for (int i = 1; i <= n; i++)
    {
        printf("%lld ", dis[i]);
    }
    return 0;
}
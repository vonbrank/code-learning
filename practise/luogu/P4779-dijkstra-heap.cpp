#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
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
struct Dis
{
    long long dis;
    int p;

    bool operator<(const Dis &b) const
    {
        return dis > b.dis;
    }

    // friend bool operator<(const Dis &a, const Dis &b)
    // {
    //     return a.dis < b.dis;
    // }
};

void addedge(int u, int v, int w)
{
    ++cnt;
    G[cnt].to = v;
    G[cnt].w = w;
    G[cnt].next = head[u];
    head[u] = cnt;
}
void dijkstra_heap(int s)
{
    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    dis[s] = 0;
    priority_queue<Dis> MinDis;
    Dis tmp;
    tmp.dis = 0;
    tmp.p = s;
    MinDis.push(tmp);
    for (int i = 1; i <= n; i++)
    {
        int k;
        long long mn = INF;

        tmp = MinDis.top();
        while (vis[tmp.p])
        {
            MinDis.pop();
            tmp = MinDis.top();
        }
        mn = tmp.dis;
        k = tmp.p;

        vis[k] = true;
        for (int j = head[k]; j; j = G[j].next)
        {
            int v = G[j].to;
            int w = G[j].w;
            if (vis[v])
                continue;
            if (dis[v] > dis[k] + w)
            {
                dis[v] = dis[k] + w;
                tmp.p = v;
                tmp.dis = dis[v];
                MinDis.push(tmp);
            }
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
    dijkstra_heap(s);
    for (int i = 1; i <= n; i++)
    {
        printf("%lld ", dis[i]);
    }
    return 0;
}
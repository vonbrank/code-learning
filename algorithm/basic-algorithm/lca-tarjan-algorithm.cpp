#include <iostream>
#include <cstdio>
#include <vector>
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
void tarjan(u)
{
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
    for (int i)
        tarjan(s);
    return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 505;
const int maxe = 50050;
int n, m, e, cnt, ans;
bool used[maxn << 1];
int head[maxn << 1], girl[maxn << 1];
struct Node
{
    int to, next;
} G[maxe << 1];
void addedge(int u, int v)
{
    ++cnt;
    G[cnt].to = v;
    G[cnt].next = head[u];
    head[u] = cnt;
}
bool find(int u)
{
    for (int j = head[u]; j; j = G[j].next)
    {
        int v = G[j].to;
        if (!used[v])
        {
            used[v] = true;
            if (girl[v] == 0 || find(girl[v]))
            {
                girl[v] = u;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    scanf("%d %d %d", &n, &m, &e);
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addedge(u, n + v);
        addedge(n + v, u);
    }
    for (int i = 1; i <= n; i++)
    {
        memset(used, 0, sizeof(used));
        if (find(i))
            ans++;
    }
    printf("%d", ans);
    return 0;
}
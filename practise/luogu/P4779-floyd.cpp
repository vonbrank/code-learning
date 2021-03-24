#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1050;
int n, m, s;
int G[maxn][maxn];
int main()
{
    memset(G, 63, sizeof(G));
    // printf("%d", G[1][1]);
    // return 0;
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i <= n; i++)
        G[i][i] = 0;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        G[u][v] = min(G[u][v], w);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (G[i][k] + G[k][j] < G[i][j])
                    G[i][j] = G[i][k] + G[k][j];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", G[s][i]);
    }
    return 0;
}
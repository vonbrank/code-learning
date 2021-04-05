#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
using namespace std;
const int maxn = 2050;
int n, m, T;
bool flag;
char mp[maxn][maxn], mp_now[maxn][maxn], mp_Qi[maxn][maxn];
int now[maxn];
bool used[maxn];
struct Node
{
    int x, y;
    Node operator+(const Node &b) const
    {
        Node c;
        c.x = x + b.x;
        c.y = y + b.y;
        return c;
    }
};
vector<Node> mv;
vector<Node> QiB;
vector<Node> QiW;
void get_Qi(vector<Node> &Qix)
{
    Qix.clear();
    memset(mp_Qi, 0, sizeof(mp_Qi));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j] != '*')
                continue;
            for (int k = 0; k < 4; k++)
            {
                Node tmp = (Node){i, j} + mv[k];
                if (tmp.x == 0 || tmp.x == n + 1 || tmp.y == 0 || tmp.y == m + 1)
                    continue;
                if (mp[tmp.x][tmp.y] != '.')
                    continue;
                mp_Qi[tmp.x][tmp.y] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp_Qi[i][j])
                Qix.push_back((Node){i, j});
            // printf("%d", mp_Qi[i][j]);
        }
        // puts("");
    }
}

bool check(Node x)
{
    int cnt = 0;
    for (int k = 0; k < 4; k++)
    {
        int i = x.x, j = x.y;
        Node tmp = (Node){i, j} + mv[k];
        if (tmp.x == 0 || tmp.x == n + 1 || tmp.y == 0 || tmp.y == m + 1)
            continue;
        if (mp_now[tmp.x][tmp.y] != '.')
            continue;
        ++cnt;
    }
    return cnt;
}
void dfs(int depth, int num_Qi)
{
    if (depth == num_Qi)
    {

        // int now_test[] = {8, 6, 7, 5, 4, 1, 2, 0, 3};

        // for (int i = 0; i < num_Qi; i++)
        //     now[i] = now_test[i];

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                mp_now[i][j] = mp[i][j];
        }
        for (int i = 0; i < num_Qi - 1; i++)
        {
            if (!check(QiB[now[i]]))
                return;
            mp_now[QiB[now[i]].x][QiB[now[i]].y] = '@';
        }
        printf("NO\n");
        flag = true;
        // for (int i = 0; i < num_Qi; i++)
        // {
        //     printf("(%d, %d) ", QiB[now[i]].x, QiB[now[i]].y);
        // }
        // puts("");
        return;
    }
    for (int i = 0; i < num_Qi; i++)
    {
        if (used[i])
            continue;
        used[i] = true;
        now[depth] = i;
        dfs(depth + 1, num_Qi);

        used[i] = false;
        now[depth] = 0;
        if (flag)
            return;
    }
}

int main()
{
    scanf("%d", &T);
    mv.push_back((Node){0, -1});
    mv.push_back((Node){0, 1});
    mv.push_back((Node){1, 0});
    mv.push_back((Node){-1, 0});
    while (T--)
    {
        flag = false;
        memset(mp, 0, sizeof(mp));
        memset(mp_now, 0, sizeof(mp_now));
        memset(mp_Qi, 0, sizeof(mp_Qi));
        QiB.clear();
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", mp[i] + 1);
        }
        get_Qi(QiB);

        // for (int i = 0; i < QiB.size(); i++)
        // {
        //     printf("(%d, %d) ", QiB[i].x, QiB[i].y);
        // }
        // puts("");
        dfs(0, QiB.size());
        if (!flag)
            printf("YES\n");
    }
    return 0;
}
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1050;
class Tuple
{
public:
    int _x_, _y_;
    Tuple()
    {
        _x_ = _y_ = 0;
    }
    void val(int x_, int y_)
    {
        _x_ = x_;
        _y_ = y_;
    }
    Tuple operator+(const Tuple &b_)
    {
        Tuple c_;
        c_._x_ = this->_x_ + b_._x_;
        c_._y_ = this->_y_ + b_._y_;
        return c_;
    }
};
int n, m;
int mp[maxn][maxn], ans[maxn][maxn];
struct Node
{
    Tuple c;
    int d;
};
bool check(Tuple p, Tuple q)
{
    int x = p._x_, y = p._y_;
    int a = q._x_, b = q._y_;
    if (ans[x][y])
        return false;
    if (x == 0 || y == 0)
        return false;
    if (x == n + 1 || y == n + 1)
        return false;
    if (mp[x][y] ^ mp[a][b])
        return true;
    return false;
}
int bfs(int x, int y)
{
    if (ans[x][y])
        return ans[x][y];

    Tuple mv[4];
    mv[0].val(0, 1);
    mv[1].val(0, -1);
    mv[2].val(1, 0);
    mv[3].val(-1, 0);

    Node tmp;
    tmp.c.val(x, y);
    tmp.d = 1;

    queue<Node> tree;
    tree.push(tmp);

    vector<Tuple> zone;

    int ansn = 0;
    ans[x][y] = 1;

    while (!tree.empty())
    {
        tmp = tree.front();
        tree.pop();
        zone.push_back(tmp.c);
        ansn++;
        for (int i = 0; i < 4; i++)
        {
            Node now;
            now.c = tmp.c + mv[i];
            now.d = tmp.d + 1;
            if (!check(now.c, tmp.c))
                continue;
            tree.push(now);
            ans[now.c._x_][now.c._y_] = ansn;
        }
    }
    for (int i = 0; i < zone.size(); i++)
    {
        int x_ = zone[i]._x_;
        int y_ = zone[i]._y_;
        ans[x_][y_] = ansn;
    }
    return ansn;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char l[5];
            scanf("%1s", l);
            mp[i][j] = l[0] - '0';
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", bfs(x, y));
    }
    return 0;
}
#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;
const int maxn = 100500;
class Point
{
public:
    long long x, y, dis;
    Point(long long x_, long long y_)
    {
        x = x_;
        y = y_;
        dis = sqrt(x * x + y * y);
    }
    bool operator<(const Point &b) const
    {
        return dis > b.dis;
    }
};
int t, n;
double ans;
priority_queue<Point> X, Y;
double P_dis(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        ans = 0;
        while (!X.empty())
            X.pop();
        while (!Y.empty())
            Y.pop();

        scanf("%d", &n);
        for (int i = 1; i <= n * 2; i++)
        {
            long long x, y;
            scanf("%lld %lld", &x, &y);
            Point tmp(x, y);
            if (x == 0)
            {
                X.push(tmp);
            }
            if (y == 0)
            {
                Y.push(tmp);
            }
        }
        while (X.size() > n)
        {
            X.pop();
        }
        while (Y.size() > n)
        {
            Y.pop();
        }

        while (!X.empty())
        {
            ans += P_dis(X.top(), Y.top());
            X.pop();
            Y.pop();
        }

        printf("%.15lf\n", ans);
        /*
        printf("%d:\n", t);
        while (!X.empty())
        {
            Point tmp = X.top();
            printf("%d %d\n", tmp.x, tmp.y);
            X.pop();
        }
        while (!Y.empty())
        {
            Point tmp = Y.top();
            printf("%d %d\n", tmp.x, tmp.y);
            Y.pop();
        }
        printf("\n");
        */
    }

    // while (!X.empty())
    // {
    //     Point tmp = X.top();
    //     printf("%d %d\n", tmp.x, tmp.y);
    //     X.pop();
    // }
    // while (!Y.empty())
    // {
    //     Point tmp = Y.top();
    //     printf("%d %d\n", tmp.x, tmp.y);
    //     Y.pop();
    // }
    return 0;
}

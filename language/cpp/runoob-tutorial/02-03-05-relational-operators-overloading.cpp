#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
class Box
{
private:
    double l_, b_, h_, v_;

public:
    Box(double l = 1.0, double b = 2.0, double h = 3.0)
    {
        l_ = l;
        b_ = b;
        h_ = h;
        v_ = l * b * h;
    }
    bool operator>(const Box &b)
    {
        return this->v_ > b.v_;
    }
    void print()
    {
        printf("%lf %lf %lf %lf\n", l_, b_, h_, v_);
    }
};

struct Dis
{
    long long dis;
    int p;

    bool operator<(const Dis &b)
    {
        return dis < b.dis;
    }

    // friend bool operator<(const Dis &a, const Dis &b)
    // {
    //     return a.dis < b.dis;
    // }
};

int main()
{
    priority_queue<Dis> MinDis;
    Box box1;
    Box box2(2.0, 3.0, 4.0);
    box1.print();
    box2.print();
    printf("%d\n", box2 > box1);
    return 0;
}
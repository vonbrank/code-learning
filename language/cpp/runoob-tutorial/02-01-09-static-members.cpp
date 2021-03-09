#include <iostream>
#include <cstdio>
using namespace std;

class Box
{
private:
    double length, breadth, width;
public:
    static int cnt;
    Box(double l, double b, double w)
    {
        length = l;
        breadth = b;
        width = w;
        cnt++;
    }
};
int Box::cnt = 0;
int main()
{
    for(int i=1; i<=100; i++)
    {
        Box b_tmp(1, 2, 3);
    }
    Box b_tmp(1, 2, 3);
    printf("%d", b_tmp.cnt);
    return 0;
}
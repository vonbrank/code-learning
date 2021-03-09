#include <iostream>
#include <cstdio>
using namespace std;
class Box
{
private:
    double l_, b_, h_;
public:
    Box(double l = 1.0, double b = 2.0, double h = 3.0)
    {
        l_ = l;
        b_ = b;
        h_ = h;
    }
    Box operator+ (const Box& b)
    {
        Box c;
        c.l_ = this -> l_ + b.l_;
        c.b_ = this -> b_ + b.b_;
        c.h_ = this -> h_ + b.h_;
        return c;
    }
    void print()
    {
        printf("%lf %lf %lf\n", l_, b_, h_);
    }
};
int main()
{
    Box box1;
    Box box2(2.0, 3.0, 4.0);
    Box box3 = box1 + box2;
    box1.print();
    box2.print();
    box3.print();
    return 0;
}
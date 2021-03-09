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
    Box operator- ()
    {
        l_ = -l_;
        b_ = -b_;
        h_ = -h_;
        return *this;
    }
    void print()
    {
        printf("%lf %lf %lf\n", l_, b_, h_);
    }
};

int main()
{
    Box box1;
    box1.print();
    -box1;
    box1.print();
    return 0;
}
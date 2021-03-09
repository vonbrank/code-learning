#include <iostream>
#include <cstdio>
using namespace std;

class Box
{
private:
    double length, breadth, height;
public:
    Box(double l, double b, double h)
    {
        length = l;
        breadth = b;
        height = h;
    }
    double volume()
    {
        return length * breadth * height;
    }
    bool operator >(Box& b)
    {
        return this -> volume() > b.volume();
    }
};

int main()
{

    return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;

class Box
{
    double width;
public:
    friend void print(Box box);
    void set(double wid);
};

void Box::set(double wid)
{
    width = wid;
}

void print(Box box)
{
    printf("%lf\n", box.width);
}

int main()
{
    Box box1;
    box1.set(5.12);
    print(box1);
    return 0;
}
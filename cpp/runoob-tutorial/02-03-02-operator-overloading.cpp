// C++ 中的运算符重载
#include <iostream>
#include <cstdio>
using namespace std;

class box
{
private:
    double length;
    double breath;
    double height;
    double volume;

public:
    double Volume()
    {
        return volume;
    }
    void setData(double len, double bre, double hei)
    {
        length = len;
        breath = bre;
        height = hei;
        volume = length * breath * height;
    }
    void print()
    {
        printf("length: %lf\n", length);
        printf("breath: %lf\n", breath);
        printf("height: %lf\n", height);
        printf("volume: %lf\n", volume);
    }
    box operator+(const box &b)
    {
        box c;
        c.setData(this->length + b.length, this->breath + b.breath, this->height + b.height);
        return c;
    }
};

int main()
{
    box box1;
    box box2;
    box box3;

    box1.setData(2.0, 3.0, 4.0);
    box2.setData(3.0, 4.0, 5.0);
    box3 = box1 + box2;

    printf("box1:\n");
    box1.print();
    printf("box2:\n");
    box2.print();
    printf("box3:\n");
    box3.print();
    return 0;
}
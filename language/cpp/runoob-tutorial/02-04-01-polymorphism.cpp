#include <iostream>
#include <cstdio>
using namespace std;
class Shape
{
private:
    int width, height;

public:
    Shape(int a, int b)
    {
        width = a;
        height = b;
    }
    virtual int area() = 0;
};
class Rectangle : public Shape
{
private:
    int width, height;

public:
    Rectangle(int a, int b) : Shape(a, b)
    {
        width = a;
        height = b;
    }
    int area()
    {
        printf("Rectangle Area: %d.\n", width * height);
    }
};
class Triangle : public Shape
{
private:
    int length;

public:
    Triangle(int a, int b) : Shape(a, b)
    {
        length = a;
    }
    int area()
    {
        printf("Rectangle Area: %lf.\n", 1.732 / 4 * length * length);
    }
};

int main()
{
    Shape *sh;
    Rectangle rec(10, 5);
    Triangle tri(10, 10);
    sh = &rec;
    sh->area();
    sh = &tri;
    sh->area();
    return 0;
}
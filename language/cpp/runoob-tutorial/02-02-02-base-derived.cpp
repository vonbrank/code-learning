// 基类 & 派生类
#include <iostream>
#include <cstdio>
using namespace std;

// 基类
class Shape
{
protected:
    int width;
    int height;

public:
    void setWidth(int w)
    {
        width = w;
    }
    void setHeight(int h)
    {
        height = h;
    }
};

// 派生类
class Rectangle : public Shape
{
public:
    int getArea()
    {
        return width * height;
    }
};

int main()
{
    Rectangle Rect;
    Rect.setWidth(5);
    Rect.setHeight(7);

    // 输出对象的面积
    printf("Total Area: %d", Rect.getArea());
    return 0;
}
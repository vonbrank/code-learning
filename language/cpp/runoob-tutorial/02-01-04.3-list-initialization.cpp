//使用初始化列表来初始化字段：
#include <iostream>
#include <cstdio>

class Line
{
public:
    void setLength(double len);
    double getLength(void);
    Line(double len); // 这是构造函数

private:
    double length;
};

Line::Line(double len) : length(len)
{
    printf("%lf", length);
}
//上面的语法等同于如下语法：
Line::Line(double len)
{
    length = len;
    printf("%lf", length);
}
//假设有一个类 C，具有多个字段 X、Y、Z 等需要进行初始化，同理地，您可以使用上面的语法，只需要在不同的字段使用逗号进行分隔，如下所示：
class C
{
    double X, Y, Z;
    C(double a, double b, double c);
};

C::C(double a, double b, double c) : X(a), Y(b), Z(c)
{
    //....
}
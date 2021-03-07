//C++ 类 & 对象
#include <iostream>
using namespace std;
class box
{
public:
    double _length_;
    double _breath_;
    double _height_;

    double get(void);
    void set(double length_, double breath_, double height_);
};

double box::get(void)
{
    return _length_ * _breath_ * _height_;
}

void box::set(double length_, double breath_, double height_)
{
    _length_ = length_;
    _breath_ = breath_;
    _height_ = height_;
}

int main()
{
    box box1;
    box1.set(20, 30, 50);
    printf("%lf", box1.get());
    return 0;
}
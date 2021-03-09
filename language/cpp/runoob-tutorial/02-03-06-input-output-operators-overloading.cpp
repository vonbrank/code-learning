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
    friend ostream &operator<<(ostream &output, const Box& b)
    {
        output << "length: " << b.l_ << " breadth: " << b.b_ << " height: " << b.h_;
        return output;
    }
    friend istream &operator>>(istream &input, Box& b)
    {
        input >> b.l_ >> b.b_ >> b.h_;
        return input;
    }
};
int main()
{
    Box box1;
    cout << box1 << endl;
    cin >> box1;
    cout << box1 << endl;
    return 0;
}
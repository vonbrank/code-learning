//C++ 中的函数重载
#include <iostream>
using namespace std;

class printData
{
public:
    void print(int i)
    {
        printf("int: %d\n");
    }
    void print(double f)
    {
        printf("double: %lf\n", f);
    }
    void print(char s[])
    {
        printf("string: %s\n", s);
    }
};

int main()
{
    printData pd;
    pd.print(5);
    pd.print(5.12);
    pd.print("Hello");
    return 0;
}
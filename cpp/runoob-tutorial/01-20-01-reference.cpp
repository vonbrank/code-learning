//C++引用
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int i = 5;
    double d = 11.7;
    int &r = i;
    double &s = d;
    printf("i = %d\n", i);
    printf("i refernce = %d\n", r);
    printf("d = %lf\n", d);
    printf("d reference = %lf\n", s);
    return 0;
}
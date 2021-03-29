#include <iostream>
#include <cstdio>
using namespace std;
namespace first_namespace
{
    void func()
    {
        printf("Inside first_namespace\n");
    }
} // namespace first_namespace
namespace second_namespace
{
    void func()
    {
        printf("Inside second_namespace\n");
    }
} // namespace second_namespace
int main()
{
    first_namespace::func();
    second_namespace::func();
    return 0;
}
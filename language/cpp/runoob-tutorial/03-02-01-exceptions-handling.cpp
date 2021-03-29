#include <iostream>
#include <cstdio>
using namespace std;

int f(int n)
{
    if (n == 0)
    {
        throw "n = 0";
    }
    if (n == 1)
    {
        throw n;
    }
    if (n == 2)
    {
        throw((double)n);
    }

    return n;
}

int main()
{
    int n;
    scanf("%d", &n);
    try
    {
        printf("%d", f(n));
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }
    catch (int msg)
    {
        cerr << msg << endl;
    }
    catch (double msg)
    {
        cerr << msg << endl;
    }
    return 0;
}
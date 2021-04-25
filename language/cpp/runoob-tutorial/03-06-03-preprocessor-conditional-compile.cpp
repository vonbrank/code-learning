#include <iostream>
#include <cstdio>
using namespace std;
#define MAX(a, b) (a > b ? a : b)
#define DEBUG
int main()
{
    int x = 10, y = 12;
    printf("%d\n", MAX(x, y));

#ifdef DEBUG
    cerr << "First text of DEBUG" << endl;
#endif

#if 0
    cerr << "annotation text" << endl;
#endif

#ifdef DEBUG
    cerr << "Second text of DEBUG" << endl;
#endif

    return 0;
}
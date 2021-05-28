#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <algorithm>
using namespace std;
stringstream ss;

struct Node
{
    int data, loc;
    bool operator<(const Node &b) const
    {
        return data < b.data;
    }
} A[100];

int main(int argc, char *argv[])
{
    int seed = time(NULL);
    if (argc > 1) //如果有参数
    {
        ss.clear();
        ss << argv[1];
        ss >> seed; //把参数转换成整数赋值给seed
    }
    srand(seed);
    //用 rand() 来返回一个随机的 int
    int n = 10;
    for (int i = 1; i <= n; i++)
    {
        A[i] = (Node){rand(), i};
        // printf("%d ", A[i].data);
        // printf("%d ", R.randInt());
    }
    sort(A + 1, A + n + 1);
    puts("");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", A[i].loc);
    }

    return 0;
}
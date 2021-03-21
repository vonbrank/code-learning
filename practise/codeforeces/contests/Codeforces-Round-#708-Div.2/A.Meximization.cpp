#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 150;
int n, t, a[maxn];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &a[i]);
        }
        sort(a+1, a+1+n);
        printf("%d ", a[1]);
        for(int i=2; i<=n; i++)
        {
            if(a[i] != a[i-1]) printf("%d ", a[i]);
        }
        for(int i=2; i<=n; i++)
        {
            if(a[i] == a[i-1]) printf("%d ", a[i]);
        }
        printf("\n");
    }
    
    return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1050;
int t, n, k;
char s[maxn];
bool check()
{
    int i = 1, j = n;
    while(s[i] == s[j] && i < j)
    {
        i++;
        j--;
    }
    if(i <= j)
    {
        if(i - 1 >= k) return true;
        else return false;
    }
    if(i > j)
    {
        if(i - 2 >= k) return true;
        else return false;
    }
}

int main()
{
    scanf("%d", &t);
    while(t)
    {
        scanf("%d %d", &n, &k);
        scanf("%s", s + 1);
        if(check())
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        
        t--;
    }
    return 0;
}
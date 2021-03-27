#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int T, n, k;
bool vis[10050];
int main()
{
    int T;
    scanf("%d", &T);
    while(T)
    {
        memset(vis, 0, sizeof(vis));
        scanf("%d %d", &n, &k);
        vis[k] = true;
        for(int i=k-1; i>=1; i--)
        {
            if(vis[i] == false && k-i != i) vis[k-i] = true;
        }
        bool flag = true;
        for(int i=1; i<=n; i++)
        {
            if(vis[i] == false)
            {
                printf("%d ", i);
                flag = false;
            }
        }
        if(flag) printf("0");
        puts("");
        T--;
    }
    return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 100000500;
int n, p, k, cnt;
int prime[maxn / 10];
bool isprime[maxn];
int main()
{
    isprime[0] = isprime[1] = true;
    scanf("%d %d", &n, &p);
    for (int i = 1; i <= n; i++)
    {
        if (!isprime[i])
        {
            prime[++cnt] = i;
            // printf("%d ", prime[cnt]);
        }
        for (int j = 1; i * prime[j] <= n && j <= cnt; j++)
        {
            isprime[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
    // printf("%d\n", cnt);
    for (int i = 1; i <= p; i++)
    {
        scanf("%d", &k);
        printf("%d\n", prime[k]);
    }
    return 0;
}
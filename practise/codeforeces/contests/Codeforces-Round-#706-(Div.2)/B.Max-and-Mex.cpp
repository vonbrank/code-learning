#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100500;
int t, n, k;
int MAX, MEX, MID, cnt;
int a[maxn];

int main()
{
    scanf("%d", &t);
    a[0] = -1;
    while(t)
    {
        //printf("checkpoint:\n");
        scanf("%d %d", &n, &k);

        


        for(int i=1; i<=n; i++)
        {
            scanf("%d", &a[i]);
        }
        sort(a+1, a+1+n);
        cnt = 0;
        for(int i=1; i<=n; i++)
        {
            if(a[i] != a[i-1]) cnt++;
            // printf("%d ", a[i]);
        }

        // puts("");

        if(k == 0)
        {
            t--;
            printf("%d\n", cnt);
            continue;
        }

        MAX = a[n];
        bool flag = true;
        for(int i=0; i<=n-1; i++)
        {
            if(a[i+1] - a[i] >= 2)
            {
                MEX = a[i] + 1;
                flag = false;
                break;
            }
        }
        if(flag) MEX = a[n] + 1;

        

        if(MEX < MAX)
        {
            if((MEX + MAX) % 2 == 1) MID = (MEX + MAX + 1) / 2;
            else MID = (MEX + MAX) / 2;
            flag = false;
            for(int i=1; i<=n; i++)
            {
                if(a[i] == MID)
                {
                    flag = true;
                    break;
                }
            }
            if(flag) printf("%d\n", cnt);
            else printf("%d\n", cnt + 1);
             //printf("MEX: %d, MAX: %d, MID: %d\n", MEX, MAX, MID);
        }
        else
        {
            printf("%d\n", cnt + k);
        }
        

        t--;
    }
    return 0;
}
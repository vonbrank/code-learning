#include <iostream>
#include <cstdio>
using namespace std;

int mirror[] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1, };
            //  0, 1, 2,  3,  4, 5,  6,  7, 8,  9, 
int T, h, m, maxn, cnt, now;
int yes[100500];
bool check(int x)
{
    int hh = x / m, mm = x % m;
    if(mirror[hh / 10] == -1 || mirror[hh % 10] == -1 || mirror[mm / 10] == -1 || mirror[mm % 10] == -1) return false;
    int hh1 = mirror[mm % 10] * 10 + mirror[mm / 10];
    int mm1 = mirror[hh % 10] * 10 + mirror[hh / 10];
    if(hh1 >= h || mm1 >= m) return false;
    return true;
}
int main()
{
    scanf("%d", &T);
    while(T)
    {
        cnt = 0;
        scanf("%d %d", &h, &m);
        char ch[10];
        scanf("%s", ch);
        now = ((ch[0] - '0') * 10 + (ch[1] - '0')) * m + (ch[3] - '0') * 10 + (ch[4] - '0');
        //printf("%d\n", now);
        maxn = h * m - 1;
        for(int i=0; i<=maxn; i++)
        {
            if(check(i))
            {
                yes[++cnt] = i;
                //printf("%d - %2d:%2d\n", i, i / m, i % m);
            }
        }
        yes[cnt + 1] = yes[1];
        for(int i=1; i<=cnt; i++)
        {
            if(yes[i] < now && now <= yes[i + 1])
            {
                printf("%02d:%02d\n", yes[i + 1] / m, yes[i + 1] % m);
                break;
            }
            if(i == cnt)
            {
                printf("%02d:%02d\n", yes[1] / m, yes[1] % m);
            }
        }
        //puts("");
        
        T--;
    }
    return 0;
}
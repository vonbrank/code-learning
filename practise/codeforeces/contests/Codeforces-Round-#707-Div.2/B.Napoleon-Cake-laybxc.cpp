#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e5+20;
int n,t;
int a[N],f[N],ans[N],p[N], cnt[N];
int main()
{
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(a,0,sizeof(a));
        memset(ans,0,sizeof(ans));
        memset(f,0,sizeof(f));
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]>1)
            {
                f[max(1,i-a[i]+1)]=i,f[i]=i;
                p[max(1,i-a[i]+1)]=i,p[i]=max(1,i-a[i]+1);
            }
            else if(a[i]==1)ans[i]=1, cnt[i]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(f[i])
            {
                int x=p[i];
                int fr=min(x,i),to=max(x,i);
                for(int j=fr;j<=to;j++)
                {
                    ans[j]=1, cnt[j]++;
                    if(f[j])
                    {
                        to=max(to,max(j,p[j]));
                    }
                }
                i=to;
            }
        }
        for(int i=1;i<=n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        for(int i=1;i<=n;i++)
        {
            cout<<cnt[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
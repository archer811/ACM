#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int n,m;
int f[8200][14];
int mp[14][14];
int v[14];
int main()
{
    int cas,i,j,k,a,b;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&v[i]);
            for(j=1;j<=n;j++)
                mp[i][j]=0;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            mp[a][b]=mp[b][a]=1;
        }
        memset(f,-1,sizeof(f));
        for(i=1;i<=n;i++)
            f[1<<i][i]=v[i];
        for(i=2;i<=n;i++)
        {
            for(j=0;j<(1<<n);j++)
            {
                for(k=1;k<=n;k++)
                {
                    if(f[j][k]==-1)continue;
                    for(int t=1;t<=n;t++)
                    {
                        if(mp[k][t]==0)continue;
                        if(j&(1<<t))continue;
                        int tmp = (j|(1<<t));
                        f[tmp][t]=max(f[tmp][t],f[j][k]+)
                    }
                }
            }
        }
        for(i=0;i<=(1<<n);i++)
        {
            for(j=1;j<=n;j++)
            {
                for(k=1;k<=n;k++)
                {
                    if(mp[j][k]==0)continue;
                    for(int t=1;t<=n;t++)
                    {
                        if(mp[k][t]==0)continue;
                        int tmp=0;
                        tmp += v[t];
                        tmp += v[k]*v[t];
                        if(mp[j][t])tmp+=v[j]*v[k]*v[t];
                        f[i][k][t]=max(f[i][k][t],f[i-1][j][k]+tmp);
                    }
                }
            }
            for(j=1;j<=n;j++)
            {
                for(k=1;k<=n;k++)
                    cout<<f[i][j][k]<<"**";
                    cout<<endl;
            }
            puts("");
        }
        int ans=0;
        if(i==1)ans=v[1];
        else
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                    ans = max(ans,f[n][i][j]);
                }
            }
        }
        cout<<ans<<endl;
    }
}

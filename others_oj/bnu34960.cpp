#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
#define ll long long
struct array
{
    int ind,v;
} g[22];
int v[22][6];
int cmp(array x,array y)
{
    return x.v>y.v;
}
ll fac[22];
ll d[2][(1<<20)+10];
int k,now[(1<<20)+10],cnt,cnt2,sum;
int vis[22];
void dfs(int pos,int end,int kind,int s,int ant)
{
    if(pos==end)
    {
        for(int i=s;i<=sum-1;i++)
        {
            for(int j=0;j<k;j++)
            {
                if(now[j]&ant)continue;
                int tmp = now[j]|ant;
                d[cnt2][tmp]+=d[cnt][now[j]];
            }
            ant = ant << 1 ;
        }
        return;
    }
    if(pos==0)
    {
        for(int i=1; i<=end; i++)
        {
            vis[i]=1;
            dfs(pos+1,end,kind,0,1);
            vis[i]=0;
        }
    }
    else
    {
        for(int i=1; i<=end; i++)
        {
            if(vis[i])continue;
            if(s+v[kind][i]>=sum)continue;
            vis[i]=1;
            int ant2 = ant | (1<<(s+v[kind][i]));
            dfs(pos+1,end,kind,s+v[kind][i],ant2);
            vis[i]=0;
        }
    }
}
int main()
{
    int i,j;
    int n;
    fac[1]=fac[0]=1;
    for(i=2; i<=20; i++)
        fac[i]=fac[i-1]*(ll)i;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        for(i = 1; i <= n; i ++)
        {
            g[i].ind = i;
            scanf("%d",&g[i].v);
            sum += g[i].v;
            for(j=1; j<=g[i].v; j++)
                scanf("%d",&v[i][j]);
        }
        sort(g+1, g+1+n ,cmp);
        memset(d,0,sizeof(d));

        ll ans=0;

        k=0;
        now[k++] = 0;

        cnt=0;
        cnt2=1;
        d[cnt][0] = 1;
        int M = 1<<sum;
        for(i = 1; i <= n; i ++ )
        {
            if(g[i].v==1)break;
            for(j=1; j<=g[i].v; j++)
                vis[j]=0;
            dfs(0,g[i].v,g[i].ind,0,0);
            k=0;
            for(j=0;j<M;j++)
            {
                d[cnt][j]=d[cnt2][j];
                d[cnt2][j]=0;
                if(d[cnt][j])
                    now[k++]=j;
            }
        }
        for(j=0;j<M;j++)
        {
            ans += d[cnt][j];
        }
        if(i<=n)
        {
            ans = ans*fac[n-i+1];
        }
        printf("%lld\n",ans);
    }
    return 0;
}

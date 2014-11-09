#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
#ifdef __int64
typedef __int64 ll;
#else
typedef long long ll;
#endif
int n,x0;
const ll  inf = ((ll)1)<<40;
struct O
{
    ll x,y,v;
    int id;
} g[1005];
int vis[1005][1005][2];
ll d[1005][1005][2],sum[1005];
int cmp(O x,O y)
{
    return x.x<y.x;
}
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&x0)!=EOF)
    {
        int flag=0;
        sum[0]=0;
        for(i=1; i<=n; i++)
        {
            scanf("%lld",&g[i].x);
            if(g[i].x==x0)flag=1;
        }
        for(i=1; i<=n; i++)
        {
            scanf("%lld",&g[i].y);
        }
        for(i=1; i<=n; i++)
        {
            scanf("%lld",&g[i].v);
            g[i].id=0;
        }
        //if(flag==0)
        {
            g[n+1].x=x0;
            g[n+1].id=1;
            g[n+1].y=0;
            g[n+1].v=0;
            n++;
        }
        sort(g+1,g+1+n,cmp);
        ll ss=0;
        for(i=1; i<=n; i++)
        {
            sum[i]=sum[i-1]+g[i].v;
            ss += g[i].y;
            //cout<<g[i].x<<" "<<sum[i]<<endl;
        }
        for(i=1; i<=n; i++)
        {
            if(g[i].id==1)
            {
                flag=i;
                break;
            }
        }
        memset(vis,0,sizeof(vis));

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                d[i][j][0]=d[i][j][1]=-inf;
        }
        vis[flag][flag][0]=vis[flag][flag][1]=1;
        d[flag][flag][0]=d[flag][flag][1]=ss;
        for(i=flag-1;i>=1;i--)
        {
            int l = i;
            int r = flag;
            d[i][flag][0]=d[i+1][flag][0]-(sum[l]+sum[n]-sum[r])*(g[l+1].x-g[l].x);
        }
        for(i=flag+1;i<=n;i++)
        {
            int l = flag;
            int r = i;
            d[flag][i][1]=d[flag][i-1][1]-(sum[l-1]+sum[n]-sum[r-1])*(g[r].x-g[r-1].x);
        }
        for(i=flag; i>=1; i--)
        {
            for(j=flag; j<=n; j++)
            {
                if(i==flag || j==flag)continue;
                int l = i,r = j;
                int x = l+1,y = r;
                int k =0;
                ll tmp0 = d[x][y][0];
                ll tmp1 = d[x][y][1];
                tmp0 = tmp0-(sum[l]+sum[n]-sum[r])*(g[l+1].x-g[l].x);
                tmp1 = tmp1-(sum[l]+sum[n]-sum[r])*(g[r].x-g[l].x);
                vis[l][r][k]=1;
                d[l][r][k]=max(tmp0,tmp1);

                x = l;y = r-1;
                k = 1;
                tmp0 = d[x][y][0];
                tmp1 = d[x][y][1];
                tmp0 = tmp0-(sum[l-1]+sum[n]-sum[r-1])*(g[r].x-g[l].x);
                tmp1 = tmp1-(sum[l-1]+sum[n]-sum[r-1])*(g[r].x-g[r-1].x);
                vis[l][r][k]=1;
                d[l][r][k]=max(tmp0,tmp1);

            }
        }
        ll ans = max(d[1][n][0],d[1][n][1]);
        double ans2 = (double)ans*1.0/1000;
        printf("%.3f\n",ans2);
        //cout<<d[1][n][0]<<" "<<<<endl;
    }
    return 0;
}

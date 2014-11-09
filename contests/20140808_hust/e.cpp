#include<iostream>
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
int a[105][105];
int vis[105][105];
const int inf = 0x3fffffff;
int main()
{
    int i,j,t;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int cas=0;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
                scanf("%d",&a[i][j]);
        }
        memset(vis,0,sizeof(vis));
        int flag=0;
        while(1)
        {
            int f=0;
            int M=inf;
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=m;j++)
                {
                    if(vis[i][j]==0&&a[i][j]<M)
                        M=a[i][j];
                }
            }
            if(M>=inf)break;
            for(i=1; i<=n; i++)
            {
                int sum1=0;
                int sum2=0;
                for(j=1; j<=m; j++)
                {
                    if(vis[i][j]==0)sum1++;
                    else continue;
                    if(a[i][j]==M)sum2++;
                }
                if(sum1&&sum2==sum1)
                {
                    f=1;
                    //cout<<i<<endl;
                    for(j=1; j<=m; j++)
                        vis[i][j]=1;
                }
            }
            for(j=1; j<=m; j++)
            {
                int sum1=0;
                int mark=inf;
                int sum2=0;
                for(i=1;i<=n;i++)
                {
                    if(vis[i][j]==0)sum1++;
                    else continue;
                    if(a[i][j]==M)sum2++;
                }
                if(sum1&&sum2==sum1)
                {
                    f=1;
                    //cout<<j<<"()"<<endl;
                    for(i=1;i<=n;i++)
                        vis[i][j]=1;
                }
            }
            if(f==0)break;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(vis[i][j]==0)flag=1;
                //cout<<vis[i][j]<<" ";
            }
            //cout<<endl;
        }
        if(flag==0)printf("Case #%d: YES\n",++cas);
        else printf("Case #%d: NO\n",++cas);
    }
    return 0;
}

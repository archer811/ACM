#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<vector>
using namespace std;
const double eps = 1e-4;
double r[1005];
struct o
{
    double x,y;
}s[1005];
int f[1005][1005];
int ans[10005];
const int inf = 0x3fffffff;
int n;
double dis(int a,int b)
{
    return (s[a].x-s[b].x)*(s[a].x-s[b].x)+(s[a].y-s[b].y)*(s[a].y-s[b].y);
}
int d[1005],pre[1005],vis[1005];
int main()
{
    int i,j;
    scanf("%d",&n);
    {

        for(i=1;i<=n;i++)
            scanf("%lf",&r[i]);
        if(n==1)
        {
            puts("0");
        }
        s[1].x=s[1].y=r[1];
        memset(f,0,sizeof(f));
        double M=r[1]*2;
        for(i=2;i<=n;i++)
        {
            s[i].y=r[i];
            s[i].x=r[i];
            int flag=-1;
            for(j=1;j<i;j++)
            {
                double tmp = r[j]-r[i];
                if(tmp<0)tmp=-tmp;
                tmp = sqrt((r[i]+r[j])*(r[i]+r[j])-(tmp*tmp));
                if(s[i].x<s[j].x+tmp)
                    s[i].x=s[j].x+tmp,flag=j;
            }
            //cout<<i<<"*"<<s[i].x<<" "<<s[i].y<<" "<<flag<<endl;
            if(s[i].x+r[i]>M)
                M=s[i].x+r[i];
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<i;j++)
            {
                //if(i==9&&j==7)
                //    cout<<fabs(dis(i,j)-(r[i]+r[j])*(r[i]+r[j]))-eps<<"LJ"<<endl;
                if(fabs(dis(i,j)-(r[i]+r[j])*(r[i]+r[j]))<eps)
                {
                    f[i][j]=f[j][i]=1;
                   // cout<<i<<" * "<<j<<endl;
                }

            }
        }
        for(i=1;i<=n;i++)
        {
            //cout<<i<<"~"<<s[i].x<<"  "<<r[i]<<endl;
            if(fabs(s[i].x-r[i])<eps)
            {
                f[0][i]=f[i][0]=1;
                //cout<<0<<" * "<<i<<endl;
            }

            if(fabs(s[i].x+r[i]-M)<eps)
            {
                f[i][n+1]=f[n+1][i]=1;
                //cout<<i<<" * "<<n+1<<endl;
            }
        }
        for(i=0;i<=n+1;i++)
        {
            pre[i]=-1;
            d[i]=inf;
            vis[i]=0;
        }
        d[0]=0;
        for(i=1;i<=n+1;i++)
        {
            int tt=1;
            if(i==n+1)tt=0;
            for(j=0;j<=n+1;j++)
            {
                if(f[i][j]==0)continue;
                if(d[i]>d[j]+tt)
                {
                    d[i]=d[j]+tt;
                    pre[i]=j;
                }
            }
        }
//        for(i=0;i<=n+1;i++)
//        {
//            cout<<i<<"()"<<d[i]<<" "<<pre[i]<<endl;
//        }
        int tmp = pre[n+1];
        while(tmp!=-1)
        {
            vis[tmp]=1;
            tmp = pre[tmp];
        }
        printf("%d\n",n-d[n+1]);
        for(i=1;i<=n;i++)
        {
            if(vis[i])continue;
            printf("%d\n",i);
        }
    }
    return 0;
}

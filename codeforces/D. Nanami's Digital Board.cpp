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
int a[1005][1005];
int n,m;
const int N = 1005;
int l[N+10][N+10],r[N+10][N+10],u[N+10][N+10],d[N+10][N+10];
int g[N+10],g2[N+10];
const int inf = 0x3fffffff;
void output()
{
    int i,j;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int i,j,q;
    int fk=0;
    while(scanf("%d%d%d",&n,&m,&q)!=EOF)
    {
        fk++;
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        memset(u,0,sizeof(u));
        memset(d,0,sizeof(d));
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                if(a[i][j])
                    l[i][j]=l[i][j-1]+1;
            }
        }
        for(i=1; i<=n; i++)
        {
            for(j=m; j>=1; j--)
            {
                if(a[i][j])
                    r[i][j]=r[i][j+1]+1;
            }
        }
        for(j=1; j<=m; j++)
        {
            for(i=1; i<=n; i++)
            {
                if(a[i][j])
                    u[i][j]=u[i-1][j]+1;
            }
        }
        for(j=1; j<=m; j++)
        {
            for(i=n; i>=1; i--)
            {
                if(a[i][j])
                    d[i][j]=d[i+1][j]+1;
            }
        }
        //output();
        int op,x,y;
        for(int t=0; t<q; t++)
        {
            scanf("%d%d%d",&op,&x,&y);
            if(op==1)
            {
                a[x][y]=1-a[x][y];
//cout<<a[x][y]<<"(_"<<endl;
                for(i=y; i<=m; i++)
                {
                    if(a[x][i])
                        l[x][i]=l[x][i-1]+a[x][i];
                    else
                        l[x][i]=0;
                }
                for(i=y; i>=1; i--)
                {
                    if(a[x][i])
                        r[x][i]=r[x][i+1]+a[x][i];
                    else
                        r[x][i]=0;
                }
                for(i=x; i<=n; i++)
                {
                    if(a[i][y])
                        u[i][y]=u[i-1][y]+a[i][y];
                    else
                        u[i][y]=0;
                }
                for(i=x; i>=1; i--)
                {
                    if(a[i][y])
                        d[i][y]=d[i+1][y]+a[i][y];
                    else
                        d[i][y]=0;
                }
                //output();
            }
            else
            {
                int ans=0;
                if(a[x][y]==0)
                {
                    puts("0");continue;
                }


                for(i=0; i<=N; i++)
                    g[i]=0,g2[i]=0;
                int M = inf;
                for(i=x; i>=1; i--)
                {
                    int tmp=0;
                    if(M<inf)tmp=g[M];
                    M=min(M,l[i][y]);
                    if(M==0)break;
                    g[M]=tmp+1;
                }
                M = l[x][y];
                for(i=x+1; i<=n;i++)
                {
                    int tmp=0;
                    if(M<inf)tmp=g2[M];
                    M=min(M,l[i][y]);
                    if(M==0)break;
                    g2[M]=tmp+1;
                }
                for(i=N;i>=1;i--)
                {
                    g[i]=max(g[i],g[i+1]);
                    g2[i]=max(g2[i],g2[i+1]);
                    ans=max(ans,(g[i]+g2[i])*i);
                    //if(ans==10)cout<<"*"<<g[i]<<" "<<g2[i]<<" "<<i<<endl;
                }
//cout<<ans<<"!"<<endl;

                for(i=0; i<=N; i++)
                    g[i]=0,g2[i]=0;
                M = inf;
                for(i=x; i>=1; i--)
                {
                    int tmp=0;
                    if(M<inf)tmp=g[M];
                    M=min(M,r[i][y]);
                    if(M==0)break;
                    g[M]=tmp+1;
                }
                M = r[x][y];
                for(i=x+1; i<=n;i++)
                {
                    int tmp=0;
                    if(M<inf)tmp=g2[M];
                    M=min(M,r[i][y]);
                    if(M==0)break;
                    g2[M]=tmp+1;
                }
                for(i=N;i>=1;i--)
                {
                    g[i]=max(g[i],g[i+1]);
                    g2[i]=max(g2[i],g2[i+1]);
                    ans=max(ans,(g[i]+g2[i])*i);
                    //if(ans==10)cout<<"#"<<g[i]<<" "<<g2[i]<<" "<<i<<endl;
                }






                for(i=0; i<=N; i++)
                    g[i]=0,g2[i]=0;
                M = inf;
                for(i=y;i>=1;i--)
                {
                    int tmp=0;
                    if(M<inf)tmp=g[M];
                    M=min(M,d[x][i]);
                    if(M==0)break;
                    g[M]=tmp+1;
                }
                M = d[x][y];
                for(i=y+1; i<=m;i++)
                {
                    int tmp=0;
                    if(M<inf)tmp=g2[M];
                    M=min(M,d[x][i]);
                    if(M==0)break;
                    g2[M]=tmp+1;
                }
                for(i=N;i>=1;i--)
                {
                    g[i]=max(g[i],g[i+1]);
                    g2[i]=max(g2[i],g2[i+1]);
                    ans=max(ans,(g[i]+g2[i])*i);
                    //if(ans==10)cout<<"^"<<g[i]<<" "<<g2[i]<<" "<<i<<endl;
                }

                for(i=0; i<=N; i++)
                    g[i]=0,g2[i]=0;
                M = inf;
                for(i=y;i>=1;i--)
                {
                    int tmp=0;
                    if(M<inf)tmp=g[M];
                    M=min(M,u[x][i]);
                    if(M==0)break;
                    g[M]=tmp+1;
                }
                M = u[x][y];
                for(i=y+1;i<=m;i++)
                {
                    int tmp=0;
                    if(M<inf)tmp=g2[M];
                    M=min(M,u[x][i]);
                    if(M==0)break;
                    g2[M]=tmp+1;
                }
                for(i=N;i>=1;i--)
                {
                    g[i]=max(g[i],g[i+1]);
                    g2[i]=max(g2[i],g2[i+1]);
                    ans=max(ans,(g[i]+g2[i])*i);
                    //if(ans==10)cout<<"%"<<g[i]<<" "<<g2[i]<<" "<<i<<endl;
                }


                cout<<ans<<endl;
            }
        }
    }
    return 0;
}

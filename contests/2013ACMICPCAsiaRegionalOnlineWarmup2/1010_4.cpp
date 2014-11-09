#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int n,m,c;
int a[2000000][3],b[300010];
const int inf = 0x3f3f3f3f;
int tot;
void add(int u,int v,int w)
{
    a[++tot][0]=v;
    a[tot][1]=w;
    a[tot][2]=b[u];
    b[u]=tot;
}
void add(int u,int v,int w)
{
    a[++tot][0]=v;
    a[tot][1]=w;
    a[tot][2]=b[u];
    b[u]=tot;
}
bool in[300010];
int q[300010],d[300010];
int spfa(int S,int T)
{
    memset(d,-1,sizeof(d));
    d[S]=0;
    in[S]=true;
    q[1]=S;
    int l =0,r = 1;
    while(l!=r)
    {
        l = l==300005?1:l+1;
        int x=q[l];
        in[x]=false;
        for (int j=b[x];j;j=a[j][2])
        {
            int y=a[j][0];
            if (d[y]==-1||d[x]+a[j][1]<d[y])
            {
                d[y]=d[x]+a[j][1];
                if (!in[y])
                {
                    in[y]=true;
                    r = r==300005?1:r+1;
                    q[r]=y;
                }
            }
        }
    }
    return(d[T]);
}
int main()
{
    int i,j,k,T;
    scanf("%d",&T);
    int u,v;
    int w;
    int cas =0;
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&c);
        memset(b,0,sizeof(b));
        tot=0;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&j);
            add(j+n,i,0);
            add(i,j+n*2,0);
        }
        for(i=1;i<n;i++)
        {
            add(i+2*n,i+1+n,c);
            add(i+1+n*2,i+n,c);
        }
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }
        printf("Case #%d: ",++cas);
        printf("%d\n",spfa(1,n));
    }
}

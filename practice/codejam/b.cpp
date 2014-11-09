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
int n;
const int inf = 0x3fffffff;
const int maxn = 2005;
int head[maxn],tot;
struct array
{
    int to,next;
} edge[maxn*2];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int num[maxn];
void dfs(int u,int fa)
{
    int i,j;
    num[u]=1;
    for(i=head[u]; i!=-1; i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        dfs(v,u);
        num[u]+=num[v];
    }
}
int anst[maxn];
int dfs2(int u,int fa)
{
    int i,j;
    int sum=0;
    int f=0;
    int yi=inf,er=inf,f1=-1,f2=-1;
    for(i=head[u]; i!=-1; i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        dfs2(v,u);
        sum += anst[v];
        f++;


        int tt =-num[v]+anst[v];

        if(f1==-1)yi=tt,f1=0;
        else if(f2==-1)
        {
            if(tt<yi)
            {
                er=yi;yi=tt;
            }
            else er=tt;
            f2=0;
        }
        else
        {
             if(tt<yi)er=yi,yi=tt;
             else if(tt<er)er=tt;
        }



    }
    if(f==0)return anst[u]=0;
    if(f==1)return anst[u]=num[u]-1;
    if(f==2)return anst[u]=sum;
    if(f>2)
    {
        //cout<<yi<<"**"<<er<<endl;
        return anst[u]=num[u]-1+yi+er;
        //return anst[u]=num[u]-1+anst[f1]+anst[f2]-num[f1]-num[f2];
    }
}
int main()
{
    int i,j,t;
    freopen("B-large-practice.in","r",stdin);
    freopen("out2.txt","w",stdout);
    scanf("%d",&t);
    int a,b;
    int cas=0;
    while(t--)
    {
        memset(head,-1,sizeof(head));
        tot=0;
        scanf("%d",&n);
        for(i=0; i<n-1; i++)
        {
            scanf("%d%d",&a,&b);
            add(a,b);
            add(b,a);
        }
        int ans=-1;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
                num[j]=0;
            dfs(i,-1);
            int Max=dfs2(i,-1);
            if(ans==-1||ans>Max)
                ans=Max;
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
}

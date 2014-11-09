#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
const int maxn = 100010;
struct
{
    int to,next;
}edge[maxn];
int head[maxn],stack[maxn],dfn[maxn],low[maxn],belong[maxn];
int instack[maxn],cnt,scnt,top,n,tot;
void add(int x,int y)
{
    edge[tot].to=y;
    edge[tot].next=head[x];
    head[x]=tot++;
}
void tarjan(int u)
{
    int i,j,t;
    dfn[u]=low[u]=++cnt;
    instack[u]=1;
    stack[top++]=u;
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        j=edge[i].to;
        if(!dfn[j])
        {
            tarjan(j);
            if(low[u]>low[j])
               low[u]=low[j];
        }
        else if(instack[j]&&dfn[j]<low[u])
            low[u]=dfn[j];
    }
    if(dfn[u]==low[u])
    {
        scnt++;
        do
        {
            t=stack[--top];
            instack[t]=0;
            belong[t]=scnt;
        }while(t!=u);
    }
}
void solve()
{
    scnt=cnt=top=0;
    memset(dfn,0,sizeof(dfn));
    for(int i=1;i<=n;i++)
      if(!dfn[i])
        tarjan(i);
}
int a[maxn],fa[maxn],num[maxn];
int find(int x)
{
    if(x==fa[x])return x;
    return fa[x]=find(fa[x]);
}
void add2(int a,int b)
{
    int x= find(a),y=find(b);
    if(x!=y)
    {
        fa[y]=x;
        num[x]+=num[y];
    }
}
int vis[maxn],ans[maxn];
int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
        memset(head,-1,sizeof(head));
        tot=0;
        fa[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&j);
            a[i]=j;
            add(i,j);
            fa[i]=i;
            num[i]=1;
            vis[i]=0;
            ans[i]=0;
        }
        solve();
        for(i=0;i<=scnt;i++)
            fa[i]=i;
        for(i=1;i<=n;i++)
        {
            j = a[i];
            add2(belong[i],belong[j]);
            vis[belong[j]]++;
        }
        int sum1=0,sum2=0;

        for(i=1;i<=scnt;i++)
        {
            j=  find(i);
            fa[i]=j;
            if(vis[i]==0)ans[j]++;
            if(j==i)
            {
                sum2+=num[j];
            }
        }
        for(i=1;i<=scnt;i++)
        {
           // cout<<sum1<<" "<<i<<" * "<<ans[i]<<endl;
            if(fa[i]==i)
            sum1+=max(1,ans[i]);
        }
        //sum1=max(sum1,)
        printf("%d %d\n",sum1,sum2);
    }
    return 0;
}

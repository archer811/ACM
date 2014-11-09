#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int N = 111;
const int maxn = 111111;
int head[N],dfn[N],low[N],instack[N],stack[N];
vector<int>belong[N];
int tot,cnt,top,scnt,n;
struct array
{
    int to,next;
}edge[maxn];
void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
void init()
{
    memset(head,-1,sizeof(head));
    memset(instack,0,sizeof(instack));
    for(int i=0;i<N;i++)
        belong[i].clear();
    tot=0;
}
void tarjan(int u)
{
   int i,j,t;
   dfn[u]=low[u]=++cnt;
   instack[u]=1;
   stack[top++]=u;
   for(i=head[u];i!=-1;i=edge[i].next)
   {
       int v = edge[i].to;
       if(!dfn[v])
       {
           tarjan(v);
           low[u]=min(low[u],low[v]);
       }
       else if(instack[v]&&dfn[v]<low[u])
        low[u]=dfn[v];
   }
   if(dfn[u]==low[u])
   {
       scnt++;
       do
       {
           t = stack[--top];
           instack[t]=0;
           belong[scnt].push_back(t);
       }while(t!=u);
   }
}
void solve()
{
    scnt=cnt=top=0;
    memset(dfn,0,sizeof(dfn));
    for(int i=1;i<=n;i++)
        if(!dfn[i])tarjan(i);
}
int main()
{
    int i,j,k,cas;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d",&n);
        init();
        for(i=1;i<=n;i++)
        {
            while(scanf("%d",&j))
            {
                 if(j==0)break;
                 addedge(i,j);
            }
        }
        solve();
        cout<<scnt<<endl;
        if(scnt>2)puts("No solution");
        else
        {
            printf("%d",belong[0].size());
            printf("%d",belong[1].size());
        }
    }
}

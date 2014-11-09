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
}edge[600005];
#define ll __int64
const ll mod = 1000000007;
ll w[100005];
ll anssum=0,ans=1;
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
        int mark=-1,num=0;
        ll ww=-1;
        do
        {
            t=stack[--top];
            if(ww==-1)
            {
                ww=w[t];num=1;
            }
            else
            {
                if(ww>w[t])
                {
                    ww=w[t];num=1;
                }
                else if(ww==w[t])
                    num++;
            }
            instack[t]=0;
            belong[t]=scnt;
        }while(t!=u);

        if(ww!=-1)
        {
            //cout<<"  **  "<<ww<<" "<<num<<" "<<anssum<<endl;
            anssum += ww;
            (ans *= (ll)num)%=mod;
        }
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

int main()
{
    int i,j;
    while(cin>>n)
    {
        for(i=1;i<=n;i++)
            scanf("%I64d",&w[i]);
        int m;
        scanf("%d",&m);
        memset(head,-1,sizeof(head));
        tot=0;
        int u,v;
        while(m--)
        {
            scanf("%d%d",&u,&v);
            add(u,v);
        }
        anssum=0;ans=1;
        solve();

        cout<<anssum<<" "<<ans<<endl;
    }
    return 0;
}

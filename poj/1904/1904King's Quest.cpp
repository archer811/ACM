#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 4005;
const int maxm = 2000006*2;
int head[maxn],dfn[maxn],low[maxn],stack[maxn],instack[maxn];
int belong[maxn];
int tot,scnt,cnt,top;
int n;
struct array
{
    int to,next;
}edge[maxm];
void init()
{
    tot=0;top=0;
    cnt=0;scnt=0;
    memset(head,-1,sizeof(head));
    memset(belong,0,sizeof(belong));
    memset(dfn,0,sizeof(dfn));
}
void add(int a,int b)
{
    edge[tot].to=b;
    edge[tot].next=head[a];
    head[a]=tot++;
}
void tarjan(int u)
{
    int i,j;
    dfn[u]=low[u]=++cnt;
    instack[u]=1;
    stack[top++]=u;
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(dfn[v]==0)
        {
            tarjan(v);
            if(low[v]<low[u])
                low[u]=low[v];
        }
        else if(instack[v]&&dfn[v]<low[u])
            low[u]=dfn[v];
    }
    if(dfn[u]==low[u])
    {
        scnt++;
        int t;
        do
        {
            t = stack[--top];
            belong[t]=scnt;
            instack[t]=0;
        }while(t!=u);
    }
}
void solve()
{
    for(int i=1;i<=n*2;i++)
    {
        if(dfn[i]==0)
            tarjan(i);
    }
}
vector<int>ans[maxn];
int mark[2005][2005];
int main()
{
    int i,j,k,d;
    while(scanf("%d",&n)!=EOF)
    {
        init();
        for(i=1;i<=n;i++)
            ans[i].clear();
        memset(mark,0,sizeof(mark));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&k);
            for(j=1;j<=k;j++)
            {
                scanf("%d",&d);
                mark[i][d]=1;
                d += n;
                add(i,d);
            }
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&j);
            j+=n;
            add(j,i);
        }
        solve();
//        for(i=1;i<=n*2;i++)
//        {
//            cout<<i<<" "<<belong[i]<<endl;
//        }
        for(i=1;i<=n;i++)
        {
            for(j=n+1;j<=n+n;j++)
            {
                if(belong[i]==belong[j]&&mark[i][j-n])
                    ans[i].push_back(j-n);
            }
        }
        for(i=1;i<=n;i++)
        {
            printf("%d",ans[i].size());
            for(j=0;j<ans[i].size();j++)
                printf(" %d",ans[i][j]);
            puts("");
        }
    }
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
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

const int maxn = 55;
int head[maxn],tot;
struct Edge
{
    int to,next;
} edge2[maxn*maxn*3];
void add(int u,int v)
{
    edge2[tot].to=v;
    edge2[tot].next=head[u];
    head[u]=tot++;
}
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
int n,m;
int wv[22],pv[55],mp[22][55],f[55][55];
int stack[maxn],dfn[maxn],low[maxn],belong[maxn];
int instack[maxn],cnt,scnt,top;
int sum[55];
void tarjan(int u)
{
    int i,j,t;
    dfn[u]=low[u]=++cnt;
    instack[u]=1;
    stack[top++]=u;
    for(i=head[u]; i!=-1; i=edge2[i].next)
    {
        j=edge2[i].to;
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
            sum[scnt]+=pv[t];
            belong[t]=scnt;
        }
        while(t!=u);
    }
}
void solve()
{
    scnt=cnt=top=0;
    memset(dfn,0,sizeof(dfn));
    for(int i=1; i<=m; i++)
        if(!dfn[i])
            tarjan(i);
}
struct E
{
    int to,next,cap;
} edge[maxn*maxn*3+22*55*2];
const int vm = 22+55+100;
int gap[vm],dist[vm],cur[vm],pre[vm];
int e;
void init()
{
    e=0;
    memset(head,-1,sizeof(head));
}
const int inf = 0x3fffffff;
void addedge(int u,int v,int c)
{
    edge[e].cap=c;
    edge[e].next=head[u];
    edge[e].to=v;
    head[u]=e++;
    edge[e].cap=0;
    edge[e].next=head[v];
    edge[e].to=u;
    head[v]=e++;
}
int sap(int s,int t,int n)
{
    memset(dist,0,sizeof(dist));
    memset(gap,0,sizeof(gap));
    memcpy(cur,head,sizeof(head));
    int res = 0;
    int u=pre[s]=s;
    int aug = inf;
    gap[0]=n;
    while(dist[s]< n)
    {
loop:
        for(int &i=cur[u]; i!=-1; i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].cap&&dist[u]==dist[v]+1)
            {
                aug=min(aug,edge[i].cap);
                pre[v]=u;
                u=v;
                if(v==t)
                {
                    res+=aug;
                    for(u=pre[u]; v!=s; v=u,u=pre[u])
                    {
                        edge[cur[u]].cap-=aug;
                        edge[cur[u]^1].cap+=aug;
                    }
                    aug=inf;
                }
                goto loop;
            }
        }
        int mindist = n;
        for(int i=head[u]; i!=-1; i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].cap&&mindist>dist[v])
            {
                cur[u]=i;
                mindist=dist[v];
            }
        }
        if((--gap[dist[u]])==0)
            break;
        dist[u]=mindist+1;
        gap[dist[u]]++;
        u=pre[u];
    }
    return res;
}
int vis[22][55];
int main()
{
    int i,j,t;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        int tmp=0;
        for(i=1; i<=n; i++)
            scanf("%d",&wv[i]),tmp+=wv[i];
        for(i=1; i<=m; i++)
            scanf("%d",&pv[i]);
        memset(mp,0,sizeof(mp));
        memset(head,-1,sizeof(head));
        memset(sum,0,sizeof(sum));
        memset(vis,0,sizeof(vis));
        tot=0;
        for(i=1; i<=n; i++)
        {
            int k;
            scanf("%d",&k);
            int num;
            for(j=1; j<=k; j++)
            {
                scanf("%d",&num);
                num++;
                mp[i][num]=1;
            }
        }
        for(i=1; i<=m; i++)
        {
            for(j=1; j<=m; j++)
            {
                scanf("%d",&f[i][j]);
                if(f[i][j])
                {
                    add(i,j);
                }
            }
        }
        solve();
//        for(i=1; i<=scnt; i++)
//            cout<<i<<" "<<sum[i]<<endl;
        init();
        for(i=1; i<=n; i++)
        {
            addedge(0,i,wv[i]);
            for(j=1; j<=m; j++)
            {
                if(mp[i][j])
                {
                    if(vis[i][belong[j]])continue;
                    vis[i][belong[j]]=1;
                    addedge(i,belong[j]+n,inf);
                    //cout<<i<<" * "<<belong[j]+n<<endl;
                }
            }
        }
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(f[i][j]==0)continue;
                if(belong[i]==belong[j])continue;
                addedge(belong[i]+n,belong[j]+n,inf);
                //cout<<belong[i]+n<<"  "<<belong[j]+n<<endl;
            }
        }
        for(i=1;i<=scnt;i++)
        {
            addedge(n+i,n+m+1,sum[i]);
            //cout<<n+i<<" () "<<n+m+1<<endl;
        }
        int ans = sap(0,n+m+1,2+n+scnt);
        printf("Case #%d: %d\n",++cas,tmp-ans);
    }
    return 0;
}

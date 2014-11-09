#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int n,m;
const int maxn = 20005;
const int maxm = 110000;
int head[maxn],e,tot;
int mark[maxn],vis[maxn];
int kuai[maxn],siz[maxn];
struct array
{
    int to,next;
}edge[maxm*2];
int cut[maxn],low[maxn],dfn[maxn];
vector<int>last;
int N;
void init()
{
    e=0;
    tot=0;
    memset(head,-1,sizeof(head));
    memset(mark,0,sizeof(mark));
    memset(kuai,0,sizeof(kuai));
    memset(cut,0,sizeof(cut));
    memset(vis,0,sizeof(vis));
    memset(siz,0,sizeof(siz));
}
void add(int a,int b)
{
    edge[e].to=b;
    edge[e].next=head[a];
    head[a]=e++;
}
void dfs(int u,int fa)
{
    mark[u]=tot;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {

        int v = edge[i].to;
        if(v==fa)continue;
        if(mark[v])continue;
        //cout<<u<<" "<<v<<" "<<fa<<endl;
        dfs(v,u);
    }
}
void find_cut(int u,int fa,int kind,int dep)
{
    int i,j;
    //cout<<u<<"!!!!!!!!!!!!!!!!!!!!"<<endl;
    dfn[u]=low[u]=dep;
    vis[u]=1;
    int child=0;
    int t=0;
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        //if(v==fa)continue;
        if(vis[v]==1&&v!=fa&&mark[v]==kind)
        {
            if(dfn[v]<low[u])
                low[u]=dfn[v];
        }
        if(vis[v]==0)
        {
            find_cut(v,u,kind,dep+1);
            child++;
            if(low[v]<low[u])low[u]=low[v];
            //cout<<u<<" "<<v<<" "<<low[v]<<" "<<dfn[u]<<endl;
            if((fa==-1&&child>1)||(fa!=-1&&low[v]>=dfn[u]))
            {
                cut[u]=1;
                t += siz[v];
                last.push_back(siz[v]);
            }
            siz[u]+=siz[v];
        }
    }
    siz[u]++;
    N++;
    last.push_back(t);
    vis[u]=2;
}
int main()
{
    int i,j,k,t;
    scanf("%d",&t);
    int a,b;
    int cas=0;
    while(t--)
    {
        while(scanf("%d%d",&n,&m)!=EOF)
        {
            init();
            for(i=0;i<m;i++)
            {
                scanf("%d%d",&a,&b);
                add(a,b);
                add(b,a);
            }
            for(i=1;i<=n;i++)
            {
                if(mark[i]==0)
                {
                    tot++;
                    kuai[tot]=i;
                    dfs(i,-1);
                }
            }
//            for(i=1;i<=n;i++)
//                cout<<kuai[i]<<"*"<<i<<endl;
            long long ans=0;
            for(i=1;i<=tot;i++)
            {
                last.clear();
                N=0;
                find_cut(kuai[i],-1,i,1);
//                for(j=1;j<=n;j++)
//                cout<<j<<"="<<cut[j]<<endl;
                for(j=0;j<last.size();j++)
                {
                    ans += (long long)last[j]*(long long)(N-1-last[j]);
                }
            }
            printf("Case %d: %lld\n",++cas,ans);
        }
    }
}

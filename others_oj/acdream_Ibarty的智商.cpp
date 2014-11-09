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
int n,m;
struct array
{
    int a,b,c;
} s[10005];

int cmp(array x,array y)
{
    return x.c<y.c;
}
struct Edge
{
    int to,next,w;
} edge[500005];
vector<int>out[10005];
int head[10005],cur[10005],tot;
int In[10005],vis[10005];
queue<int>q;
void add(int u,int v,int w)
{
    edge[tot].to=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot++;
}

void solve()
{
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u]=1;
        for(int i=0; i<out[u].size(); i++)
        {
            int v = out[u][i];
            In[v]--;
            if(In[v]==0&&vis[v]==0)
            {
                q.push(v);
                vis[v]=1;
            }
        }
    }
}
const int inf = 0x3fffffff;
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=1; i<=n; i++)
            In[i]=0,out[i].clear();
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
            swap(s[i].a,s[i].b);
        }
        sort(s,s+m,cmp);
        memset(vis,0,sizeof(vis));
        memset(head,-1,sizeof(head));
        tot=0;
        for(i=0; i<m; i++)
        {
            out[s[i].a].push_back(s[i].b);
            add(s[i].b,s[i].a,s[i].c);
            In[s[i].b]++;
        }
        int ans=0;
        while(!q.empty())q.pop();
        for(i=1;i<=n;i++)
            cur[i]=head[i];
        while(1)
        {
            int f=0;
            for(i=1; i<=n; i++)
            {
                if(vis[i])continue;
                if(In[i]==0)
                {
                    q.push(i);
                    f=1;
                    //cout<<i<<endl;
                }
            }
            if(f)solve();
            else if(f==0)
            {
                int M=inf,o=-1;
                for(i=1;i<=n;i++)
                {
                    if(vis[i])continue;
                    //if(In[i]!=1)continue;
                    for(j=cur[i];j!=-1;j=edge[j].next)
                    {
                        int tmp = edge[j].to;
                        if(vis[tmp])continue;
                        cur[i]=j;
                       // cout<<i<<"FFF"<<edge[j].to<<endl;
                        if(edge[j].w<M)
                        {
                            M=edge[j].w;
                            o=i;
                        }
                        break;
                    }
                }
                if(o!=-1)
                {
                    f=1;
                    ans=max(ans,M);
                    //cout<<M<<endl;
                    q.push(o);
                    solve();
                }
            }
            if(f==0)break;
        }
        printf("%d\n",ans);
    }
    return 0;
}

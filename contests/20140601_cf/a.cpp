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
int w[1005];
int head[1005],tot;
struct array
{
    int to,next;
} edge[80050];
int sum[10005];
int n,m;
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int vis[1005];
const int inf =0x3fffffff;
int mp[1005][1005];
int dfs()
{
    int i,j;
    queue<int>q;
    int ans=0;
    while(1)
    {
        int M=inf;
        int f=-1;
        for(i=1; i<=n; i++)
        {
            if(vis[i])continue;
            if(sum[i]<M)
            {
                M=sum[i];f=i;
            }
        }
        cout<<M<<" * "<<f<<endl;
        if(f==-1)break;
        ans+=M;
        for(i=1; i<=n; i++)
        {
            if(vis[i])continue;
            if(sum[i]==M)
            {
                vis[i]=1;
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int u=  q.front();
            q.pop();
            for(i=1;i<=n;i++)
            {
                if(vis[i]||i==u)continue;
                if(mp[u][i])
                {
                    cout<<i<<"        "<<sum[i]<<"  "<<w[u]<<endl;
                    sum[i]-=w[u];

                }


            }
        }
        for(i=1;i<=n;i++)
            cout<<i<<"@"<<sum[i]<<endl;
    }
    return ans;
}
struct oo
{
    int x,y,ss;
}s[2100];
int cmp(oo a, oo b)
{
    return a.ss<b.ss;
}
int main()
{
    int i,j;
    while(cin>>n>>m)
    {
        memset(sum,0,sizeof(sum));
        memset(vis,0,sizeof(vis));
        memset(mp,0,sizeof(mp));
        for(i=1; i<=n; i++)
            scanf("%d",&w[i]);
        for(i=0; i<m; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            s[i].x=a;s[i].y=b;
            s[i].ss=w[a]+w[b];
        }
        sort(s,s+m,cmp);
        int tmp=0;
        for(i=0;i<m;i++)
        {
            tmp += min(w[s[i].x],w[s[i].y]);
        }
        cout<<tmp<<endl;
    }
    return 0;
}

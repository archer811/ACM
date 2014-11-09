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
#define ll long long
const int maxn = (1<<12)+10;
int head[maxn],tot;
int len[maxn];
struct array
{
    int to,next;
}edge[16777217];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int ans;
int flag;
int vis[maxn];
int in[maxn];
void dfs(int u,int num)
{
    queue<int>q;
    q.push(u);
    while(!q.empty())
    {
        int u = q.front();q.pop();
        num++;
        int f=0;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].to;
            if(vis[v])continue;
            in[v]--;
            if(in[v]==0&&f==0)
            {
                vis[v]=1;
                 q.push(v);
                 f=1;
            }

        }
        if(f==0)
        {
            for(int i=head[u];i!=-1;i=edge[i].next)
            {
                int v = edge[i].to;
                if(vis[v])continue;
                vis[v]=1;
                q.push(v);
                break;
            }
        }
    }
    cout<<num<<endl;
}
int main()
{
    int i,j,n;
    for(i=0;i<maxn;i++)
    {
        if(i&1)len[i]=len[i/2]+1;
        else len[i]=len[i/2];
    }
    while(scanf("%d",&n)&&n)
    {
        memset(head,-1,sizeof(head));
        memset(vis,0,sizeof(vis));
        memset(in,0,sizeof(in));
        tot=0;
        int M = 1<<n;
        for(i=0;i<M;i++)
        {
            for(j=0;j<M;j++)
            {
                int k = i^j;
                if(i==j)continue;
                if(len[k]>=n/2)
                {
                    //cout<<i<<" "<<j<<endl;
                    add(i,j);
                }
            }
        }
        cout<<tot<<endl;
        ans = M-1;
        flag=0;
        vis[0]=1;
        dfs(0,0);
        cout<<"end"<<endl;
    }
    return 0;
}

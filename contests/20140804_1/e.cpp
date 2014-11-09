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
const int maxn = 10005;
int head[maxn],tot;
struct Edge
{
    int to,next;
}edge[1000006];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int in[maxn];
int v[maxn],mark[maxn];
int main()
{
    int i,j,t,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&k);
        int n,m;
        scanf("%d%d",&n,&m);
        memset(head,-1,sizeof(head));
        tot=0;
        memset(in,0,sizeof(in));
        while(m--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b);
            in[b]++;
        }
        queue<int>q;
        for(i=1;i<=n;i++)
        {
            v[i]=-1;mark[i]=-1;
            if(in[i]==0)
            {
                q.push(i);
                v[i]=1;mark[i]=1;
            }
        }
        while(!q.empty())
        {
            int u = q.front();q.pop();
            if(mark[u]==2)v[u]=v[u]+1;
            for(i=head[u];i!=-1;i=edge[i].next)
            {
                int v2 = edge[i].to;
                if(v[u]>v[v2])
                {
                    v[v2]=v[u];mark[v2]=1;
                }
                else if(v[u]==v[v2])
                    mark[v2]++;
                in[v2]--;
                if(in[v2]==0)q.push(v2);
            }
        }
        int M=-1;
        for(i=1;i<=n;i++)
        {
            if(v[i]>M)M=v[i];
        }
        printf("%d %d\n",k,M);
    }
    return 0;
}

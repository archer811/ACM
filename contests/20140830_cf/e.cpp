#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
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

const int maxn = 400005;
int head[maxn],tot;
struct Edge
{
    int to,next;
}edge[maxn];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
int pre[maxn],val[maxn];
void dfs(int u,int fa)
{
    pre[u]=fa;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        dfs(v,u);
    }
}
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int i,j,n,q;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        memset(head,-1,sizeof(head));
        tot=0;
        memset(pre,-1,sizeof(pre));
        for(i=1;i<=n;i++)
            scanf("%d",&val[i]);
        for(i=1;i<=n-1;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b);
            add(b,a);
        }
        dfs(1,-1);
        while(q--)
        {
            int k,a,b;
            scanf("%d",&k);
            if(k==1)
            {
                scanf("%d",&a);
                int s=0;
                int tmp = pre[a];
                while(tmp!=-1)
                {
                    int t = gcd(val[tmp],val[a]);
                    if(t>1){s=tmp;break;}
                    tmp = pre[tmp];
                }
                if(s==0)s=-1;
                printf("%d\n",s);
            }
            else
            {
                scanf("%d%d",&a,&b);
                val[a]=b;
            }
        }
    }
    return 0;
}

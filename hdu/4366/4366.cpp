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
const int maxn = 50005;
const int maxm = 400005;
int head[maxn],tot;
struct Edge
{
    int to,next;
}edge[maxm];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
struct O
{
    int loyalty ,ablity;
}g[maxn],g2[maxn];
int cmp(O x,O y)
{
    return x.ablity<y.ablity;
}
int Mark,M;
int id[maxn],L[maxn],R[maxn];
int d[maxn];
void dfs(int u)
{
    id[u]=Mark++;
    L[u]=Mark;
    g2[Mark]=g[u];
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        dfs(v);
    }
    R[u]=Mark-1;
}
int main()
{
    int i,j,n,m,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(head,-1,sizeof(head));
        tot=0;
        int fa;
        for(i=1;i<n;i++)
        {
            scanf("%d%d%d",&fa,&g[i].loyalty,&g[i].ablity);
            add(fa,i);
        }
        Mark=0;
        dfs(0);
        for(i=0;i<n;i++)
        {
            cout<<i<<"  "<<id[i]<<"  "<<L[i]<<"  "<<R[i]<<endl;
        }
        M = sqrt(n);
        for(i=0;i<n;i+=M)
        {
            j = i+M;
            j = min(j,n);
            cout<<i<<" "<<j<<endl;
            sort(g2+i,g2+j,cmp);
            for(int k=j;k>=i;k--)
            {
                if(j==k)d[k]=g2[k].loyalty;
                else d[k]=max(d[k+1],g2[k].loyalty);
            }
        }
        for(i=0;i<n;i++)
            cout<<d[i]<<" ";
        cout<<endl;
        for(i=0;i<m;i++)
        {
            int x;
            scanf("%d",&x);
            if(head[x]==-1)
                puts("-1");
            else
            {

            }
        }
    }
    return 0;
}

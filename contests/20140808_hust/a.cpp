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
#define ll long long
const int maxn = 205;
int head[maxn],tot=0;
map<string,int>M;
struct Edge
{
    int to,next;
}edge[maxn*8];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int ans[maxn];
int flag=0;
void dfs(int u,int fa)
{
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        if(ans[v]==-1)
        {
            ans[v]=1-ans[u];
            dfs(v,u);
        }
        else if(ans[v]!=1-ans[u])
        {
            flag=1;break;
        }
    }
}
int main()
{
    int i,j,t;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        M.clear();
        memset(head,-1,sizeof(head));
        tot=0;
        int m=1;
        for(i=0;i<n;i++)
        {
            int a,b;
            string c;
            cin>>c;
            a=M[c];
            if(a==0)a=M[c]=m++;
            cin>>c;
            b=M[c];
            if(b==0)b=M[c]=m++;
            add(a,b);
            add(b,a);
        }
        memset(ans,-1,sizeof(ans));
        flag=0;
        for(i=1;i<m;i++)
        {
            if(ans[i]==-1)
            {
                ans[i]=0;
                dfs(i,-1);
            }
        }
        if(flag==0)
            printf("Case #%d: Yes\n",++cas);
        else
            printf("Case #%d: No\n",++cas);
    }
    return 0;
}

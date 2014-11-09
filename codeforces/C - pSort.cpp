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
int a[105],d[105];
int vis[105],fa[105];
int find(int x)
{
    if(x==fa[x])return x;
    return fa[x]=find(fa[x]);
}
void add(int u,int v)
{
    int x =find(u),y = find(v);
    if(x!=y)fa[y]=x;
}
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]),fa[i]=i;
        for(i=1;i<=n;i++)
            scanf("%d",&d[i]);
        memset(vis,0,sizeof(vis));
        int flag=0;
        for(i=1;i<=n;i++)
        {
            int tmp = i-d[i];
            if(tmp>=1&&tmp<=n)
            {
                add(i,tmp);
            }
            tmp = i+d[i];
            if(tmp>=1&&tmp<=n)
            {
                add(i,tmp);
            }
        }
        for(i=1;i<=n;i++)
        {
            int x=find(i),y=find(a[i]);
            if(x!=y)flag=1;
        }
        if(flag)puts("NO");
        else puts("YES");
    }
    return 0;
}

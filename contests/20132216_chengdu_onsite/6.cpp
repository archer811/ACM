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
const int inf = 0x3fffffff;
int fa[100005];
struct array
{
    int u,v,c;
} e[200005];
int cmp1(array x,array y)
{
    return x.c<y.c;
}
int cmp2(array x,array y)
{
    return x.c>y.c;
}
int find(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void add(int x,int y)
{
    if(x<=y)
        fa[y]=x;
    else fa[x]=y;
}
int vis[200005];
int main()
{
    int i,j,k,t;
    i=j=1;
    while((i+j)<=100005)
    {
        vis[i]=1;
        vis[j]=1;
        vis[i+j]=1;
        int a=i,b=j;
        i=b;
        j=a+b;
    }
    int cas=0;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0; i<=n; i++)
            fa[i]=i;
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].c);
        }
        for(i=m; i<=m+n; i++)
        {
            e[i].u=0,e[i].v=i-m+1,e[i].c=inf;
        }
        int num1=0,num2=0;
        sort(e,e+m+n,cmp1);
        for(i=0;i<m+n;i++)
            cout<<e[i].c<<endl;
        for(j=0; j<m+n; j++)
        {
            int x = find(e[j].u),y = find(e[j].v);
            if(x!=y)
                add(x,y),num1+=e[j].c;
        }
        for(i=1; i<=n; i++)
            fa[i]=i;
        sort(e,e+m+n,cmp2);
        for(i=m; i<=m+n; i++)
        {
            e[i].u=0,e[i].v=i-m+1,e[i].c=inf;
        }
        for(j=0; j<m+n; j++)
        {
            int x = find(e[j].u),y = find(e[j].v);
            if(x!=y)
                add(x,y),num2+=e[j].c;
        }
        bool flag=false;
        cout<<num1<<" "<<num2<<endl;
        for(j=num1; j<=num2; j++)
        {
            if(vis[j])
            {
                flag=true;
                break;
            }
        }
        if(flag)
            printf("Case #%d: Yes\n",++cas);
        else
            printf("Case #%d: No\n",++cas);
    }
}

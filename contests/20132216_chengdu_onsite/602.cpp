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
int fa[100005];
struct array
{
    int u,v,c;
}e[100005];
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
    fa[x]=y;
}
int vis[100005];
int main()
{
    int i,j,k,t;
    scanf("%d",&t);
    i=1;j=1;
    while(i+j<=100000)
    {
        vis[i]=1;vis[j]=1;
        vis[i+j]=1;
        int a=i,b=j;
        i=b;j=a+b;
    }
    int cas=0;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            fa[i]=i;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].c);
            int x = find(e[i].u),y=find(e[i].v);
            if(x!=y)add(x,y);
        }
        for(i=1;i<=n;i++)
        {
            if(find(i)!=1)
                break;
        }
        if(i<=n)
        {
            printf("Case #%d: No\n",++cas);continue;
        }
        sort(e,e+m,cmp1);
        int num1=0;
        j=0;
        for(i=0;i<m;i++)
        {
            int x = find(e[i].u),y = find(e[i].v);
            if(x!=y)
                add(x,y),num1+=e[i].c,j++;
            //cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].c<<" "<<num1<<endl;
            if(j==n-1)break;
        }
        for(i=1;i<=n;i++)
            fa[i]=i;
        sort(e,e+m,cmp2);
        int num2=0;
        j=0;
        for(i=0;i<m;i++)
        {
            int x = find(e[i].u),y = find(e[i].v);
            if(x!=y)
                add(x,y),num2+=e[i].c,j++;
            if(j==n-1)break;
        }
        bool flag=false;
        //cout<<num1<<" "<<num2<<endl;
        for(i=num1;i<=num2;i++)
        {
            if(vis[i]){flag=true;break;}
        }
        if(flag)
            printf("Case #%d: Yes\n",++cas);
        else
            printf("Case #%d: No\n",++cas);
    }
}

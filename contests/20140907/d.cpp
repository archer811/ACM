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
const int maxn = 100010;
const int maxm = 400015;
int head[maxn],tot;
struct Edge
{
    int to,next;
} edge[maxm];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int n,m,k;
int is[maxn],a[maxn];
int fa[maxn];
int find(int x)
{
    if(x==fa[x])return x;
    return fa[x]=find(fa[x]);
}
void uion(int x,int y)
{
    int a = find(x),b = find(y);
    if(a==b)return;
    fa[b]=a;
}
int judge(int x,int y)
{
    int a = find(x),b = find(y);
    if(a!=b)return 0;
    return 1;
}
int main()
{
    int i,j,t,x,y;
    scanf("%d",&t);
    while(t--)
    {
        memset(head,-1,sizeof(head));
        tot=0;
        scanf("%d%d%d",&n,&m,&k);
        memset(is,0,sizeof(is));
        for(i=1; i<=k; i++)
        {
            scanf("%d",&x);
            is[x]=1;
        }
        for(i=0; i<m; i++)
        {
            scanf("%d%d",&x,&y);
            add(x,y);
            add(y,x);
        }
        int L;
        scanf("%d",&L);
        for(i=1; i<=L; i++)
        {
            scanf("%d",&a[i]);
        }
        if(L<k)
        {
            puts("No");
            continue;
        }

        for(i=1; i<=n; i++)
            fa[i]=i;

        for(i=1; i<=n; i++)
        {
            if(is[i]==0)
            {
                for(j=head[i]; j!=-1; j=edge[j].next)
                {
                    int v = edge[j].to;
                    if(is[v]==0)
                        uion(v,i);
                }
            }
        }

        int flag=0;
        for(i=1; i<=L; i++)
        {
            if(i==1)
            {
                int tmp = a[i];
                is[tmp]=0;
                for(j=head[tmp]; j!=-1; j=edge[j].next)
                {
                    int v = edge[j].to;
                    if(is[v]==0)
                        uion(v,tmp);
                }
            }
            else
            {
                is[a[i]]=0;
                int tmp = a[i];
                for(j=head[tmp]; j!=-1; j=edge[j].next)
                {
                    int v = edge[j].to;
                    if(is[v]==0)
                        uion(v,tmp);
                }

                if(judge(a[i-1],a[i])==0)
                {
                    flag=1;break;
                }
            }
            if(flag)break;
        }


        x = find(1);
        for(i=2;i<=n;i++)
        {
            if(find(i)!=x)
            {
                flag=1;break;
            }
        }
        if(flag==0)puts("Yes");
        else puts("No");

    }
    return 0;
}

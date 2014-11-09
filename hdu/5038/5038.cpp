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
/*
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
}*/
const int maxn = 1000006;
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
struct array
{
    int num,id;
}g[100005];
int num[100005];
int cmp(array x,array y)
{
    if(x.num==y.num)return x.id<y.id;
    return x.num>y.num;
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        memset(num,0,sizeof(num));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&j);
            num[10000-(100-j)*(100-j)]++;
        }
        int k=0;
        for(i=0;i<=10004;i++)
        {
            if(num[i]==0)continue;
            g[k].num=num[i];
            g[k++].id=i;
        }
        sort(g,g+k,cmp);
        int flag=0;
        for(i=1;i<k;i++)
        {
            if(g[i].num!=g[0].num)flag=1;
        }
        printf("Case #%d:\n",++cas);
        if(flag==0&&k!=1)
        {
            puts("Bad Mushroom");
        }
        else
        {
            for(i=0;i<k;i++)
            {
                if(g[i].num!=g[0].num)break;
                if(i==0)printf("%d",g[0].id);
                else printf(" %d",g[i].id);
            }
            puts("");
        }
    }
    return 0;
}

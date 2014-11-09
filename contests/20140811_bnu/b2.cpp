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
const int N = 105;
int mark[N];
ll d[N][N];
const ll inf = 0x3fffffff;
struct o
{
    int x,y,v;
}s[105*105];
int fa[105];
int cmp(o a,o b)
{
    return a.v<b.v;
}
int find(int a)
{
    if(fa[a]==a)return a;
    return fa[a]=find(fa[a]);
}
int main()
{
    int i,j;
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(i=0; i<N; i++)
        {
            for(j=0; j<N; j++)
                d[i][j]=inf;
        }
        int x=n+1;
        for(i=1;i<=x;i++)
            fa[i]=i;
        for(i=1; i<=k; i++)
        {
            scanf("%d",&j);
            d[x][j]=d[j][x]=0;
        }
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                scanf("%lld",&d[i][j]);
            }
        }
        ll ans=0;
        int t=0;
        for(i=1; i<=x; i++)
        {
            for(j=1; j<=x; j++)
            {
                if(i<j)
                {
                    s[t].x=i;
                    s[t].y=j;
                    s[t++].v=d[i][j];
                }
            }
        }
        sort(s,s+t,cmp);
        int s2=0;
        for(i=0; i<t; i++)
        {
            int x2 = s[i].x;
            int y = s[i].y;
            int v = s[i].v;
            int a=find(x2);
            int b=find(y);
            if(a==b)continue;
            ans += v;
            fa[b]=a;
            s2++;
            if(s2>=n)break;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

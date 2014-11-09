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
        for(i=1;i<=k;i++)
            scanf("%d",&j);
        for(i=1;i<=n;i++)
            fa[i]=i;
        int g;
        int t=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&g);
                if(i<j)
                {
                    s[t].x=i;s[t].y=j;
                    s[t++].v=g;
                }
            }
        }
        sort(s,s+t,cmp);
        int ans=0;
        int s2=0;
        for(i=0;i<t;i++)
        {
            int x = s[i].x;
            int y = s[i].y;
            int v = s[i].v;
            int a=find(x);
            int b=find(y);
            if(a==b)continue;
            ans += v;
            fa[b]=a;
            s2++;
            if(s2>=n-k)break;
        }
        printf("%d\n",ans);
    }
    return 0;
}

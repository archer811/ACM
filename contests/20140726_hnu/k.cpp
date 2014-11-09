#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
struct array
{
    int x,y,v;
}g[100006];
int cmp1(array a,array b)
{
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}

int cmp2(array a,array b)
{
    if(a.y==b.y)return a.x<b.x;
    return a.y<b.y;
}
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        int ans=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&g[i].x,&g[i].y,&g[i].v);
            //v[make_pair(g[i].x,g[i].y)]+=g[i].v;
            if(g[i].v>ans)ans=g[i].v;
        }

        sort(g,g+n,cmp1);
        int pre=0;
        for(i=1;i<n;i++)
        {
            for(j=i)
        }

        printf("%d / 1\n",ans);
    }
    return 0;
}

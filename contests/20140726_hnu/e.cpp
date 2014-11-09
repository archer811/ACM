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

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        map<pair<int,int>,int>v;
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&g[i].x,&g[i].y,&g[i].v);
            v[make_pair(g[i].x,g[i].y)]+=g[i].v;
        }
        int ans=0;
        for(i=0;i<n;i++)
        {
            int a,b,c,d,e,f,g2,h,i2;
            a = v[make_pair(g[i].x,g[i].y)];
            b = v[make_pair(g[i].x,g[i].y-1)];
            c = v[make_pair(g[i].x+1,g[i].y)];
            d = v[make_pair(g[i].x,g[i].y+1)];
            e = v[make_pair(g[i].x-1,g[i].y)];

            f = v[make_pair(g[i].x-1,g[i].y-1)];
            g2 = v[make_pair(g[i].x+1,g[i].y-1)];
            h = v[make_pair(g[i].x+1,g[i].y+1)];
            i2 = v[make_pair(g[i].x-1,g[i].y+1)];
            ans = max(ans,a+b+e+f);

            ans = max(ans,a+b+g2+c);


            ans = max(ans,a+d+c+h);


            ans = max(ans,a+d+e+i2);
        }
        printf("%d / 1\n",ans);
    }
    return 0;
}

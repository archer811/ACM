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
struct array
{
    int s,f,m,o,index;
}g[20005];
int cmp(array x,array y)
{
    return x.s*3600+x.f*60+x.m<y.s*3600+y.f*60+y.m;
}
vector<int>ans;
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        int n,l;
        scanf("%d%d",&n,&l);
        for(i=1;i<=n;i++)
        {
            scanf("%d:%d:%d",&g[i].s,&g[i].f,&g[i].m);
            g[i].o=g[i].s*3600+g[i].f*60+g[i].m;
            g[i].index=i;
        }
        sort(g+1,g+1+n,cmp);
        ans.clear();
        int t=-l-1;
        for(i=1;i<=n;i++)
        {
            if(g[i].o<=t)continue;
            t=g[i].o+l-1;
            ans.push_back(g[i].index);
        }
        printf("%d\n",ans.size());
        sort(ans.begin(),ans.end());
        for(i=0;i<ans.size();i++)
        {
            if(i==0)printf("%d",ans[i]);
            else printf(" %d",ans[i]);
        }
        puts("");
    }
}

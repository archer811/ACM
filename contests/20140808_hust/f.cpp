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
    int p,q;
}g[100005];
int cmp(array x,array y)
{
    if(x.p==y.p)return x.q>y.q;
    return x.p<y.p;
}
int main()
{
    int i,j;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
            scanf("%d%d",&g[i].p,&g[i].q);
        if(n==1)
        {
            puts("Poor Alex");
            continue;
        }
        sort(g,g+n,cmp);
        int flag=0;
        for(i=1;i<n;i++)
        {
            if(g[i].q<g[i-1].q)flag=1;
        }
        if(flag)
            puts("Happy Alex");
        else
            puts("Poor Alex");
    }
    return 0;
}

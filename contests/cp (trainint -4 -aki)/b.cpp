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
    int t,l;
}s[33];
int cmp(array x,array y)
{
    if(x.l*y.t==x.t*y.l)return x.t<y.t;
    double t1=x.l/x.t;
    double t2=y.l/y.t;
    return t1>t2;
}
int main()
{
    int i,j,n,L;
    while(scanf("%d%d",&n,&L)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&s[i].t,&s[i].l);
        }
        sort(s,s+n,cmp);
        int t = s[0].t,l = s[0].l;
        int sum=0;
        for(i=1;;i++)
        {
            sum+=i;
            if(sum*l*t>L){sum-=i;break;}
        }
        int ans=i-1,now=i;
        ans = t+ans*t;
        L -= sum*t*l;
        while(L>0)
        {
            L-=now*l;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}

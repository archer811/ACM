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
const int N = 25010;
struct oo
{
    int t,d;
}x[N];
int cmp(oo a,oo b)
{
    if(a.d==b.d)return a.t<b.t;
    return a.d<b.d;
}
#define ll long long
struct array
{
    int g;
    bool friend operator <(array x,array y)
    {
        return x.g<y.g;
    }
};
int main()
{
    int i,j,n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&x[i].t,&x[i].d);
        }
        sort(x+1,x+1+n,cmp);
        int ans=0;
        ll sum=0;
        priority_queue<array>q;
        int flag=0;
        for(i=1;i<=n;i++)
        {
            array now;
            now.g=x[i].t;
            q.push(now);
            sum += x[i].t;
            while(!q.empty()&&sum>x[i].d)
            {
                now = q.top();
                int tmp = now.g;
                //cout<<tmp<<endl;
                q.pop();
                sum-=tmp;
                ans++;
            }
            if(q.empty()&&sum>x[i].d)
            {
                flag=1;break;
            }
        }
        if(flag||ans>=k)puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}

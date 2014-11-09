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
#define ll __int64
struct array
{
    ll val;
    int index;
    friend bool operator <(array x,array y)
    {
        return x.val>y.val;
    }

};
priority_queue<array>q;
int ans[110000];
struct o
{
    ll val;
    int index;
}a[110000];
int cmp(o x,o y)
{
    return x.val<y.val;
}
int main()
{
    int i,j,c;
    scanf("%d",&c);
    int n,m;
    while(c--)
    {
        scanf("%d%d",&n,&m);
        memset(ans,0,sizeof(ans));
        while(!q.empty())q.pop();
        for(i=0;i<m;i++)
        {
            array now;
            now.val=0;
            now.index=i;
            q.push(now);
        }
        for(i=0;i<n;i++)
        {
            scanf("%I64d",&a[i].val);
            a[i].index=i;
        }
        sort(a,a+n,cmp);
        for(i=0;i<n;i++)
        {
            array now = q.top(),next;;
            q.pop();
            //cout<<now.val<<" "<<now.index<<endl;
            next.val=now.val+a[i].val;
            next.index=now.index;
            ans[a[i].index]=now.index;
            q.push(next);
        }
        printf("%d\n", n);
        for(i=0;i<n;i++)
        {
            if(i==0)
                printf("%d",ans[i]);
            else
                printf(" %d",ans[i]);
        }
        puts("");
    }
}

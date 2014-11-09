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
ll w[100005];
ll L[100005],R[100005];
int main()
{
    int i,j;
    ll l,r,ql,qr,n;
    while(cin>>n>>l>>r>>ql>>qr)
    {
        for(i=1; i<=n; i++)
            scanf("%I64d",&w[i]);
        R[n+1]=0;
        for(i=1;i<=n;i++)
            L[i]=L[i-1]+w[i]*l;
        for(i=n;i>=1;i--)
            R[i]=R[i+1]+w[i]*r;
        ll ans=-1;
        for(i=0;i<=n;i++)
        {
            ll tmp =0;
            if(i>n-i)
            {
                tmp=(i-n+i-1)*ql;
            }
            else if(n-i>i)
                tmp = (n-i-i-1)*qr;
            if(ans==-1||tmp+L[i]+R[i+1]<ans)
                ans=tmp+L[i]+R[i+1];
        }
        cout<<ans<<endl;
    }
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
const int maxn = 100005;

#define ll __int64
ll a[maxn],b[maxn];
ll d[maxn][33];
int n;
ll find(int x,int y)
{
    ll sum=0;
    int k=0;
    if(y==x)return d[x][0];
    while((1<<(k+1))<=y-x+1)k++;
    k--;
    int tp= x+(1<<k)-1;
    return d[x][k]+find(x,y);
}
int judge(ll x)
{
    for(int i=1;i<=n;i++)
    {

    }
}
int main()
{
    int i,j;
    ll l;
    ll x,y;
    while(cin>>n>>l>>x>>y)
    {
        for(i=1;i<=n;i++)
            scanf("%I64d",&a[i]);
        for(i=1;i<n;i++)
            b[i]=a[i+1]-a[i];n--;
        for(i=1;i<=n;i++)
            d[i][0]=b[i];
        for(j=1;(1<<j)<=n;j++)
            for(i=1;i+j-1<=n;i++)
                d[i][j]=d[i][j-1]+d[i+(1<<(j-1))][j-1];
        int i,j;
        while(cin>>i>>j)
        {
            cout<<find(i,j)<<endl;
        }
        int flag=0;
        int e=-1,f=-1;
        if(!judge(x)&&!judge(l-x))flag++,e=x;
        if(!judge(y)&&!judge(l-y))flag++,f=y;
        cout<<flag<<endl;
        if(flag==1)cout<<e<<endl;
        else if(flag==2)cout<<e<<" "<<f<<endl;
    }
    return 0;
}


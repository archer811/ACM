#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define ll __int64
ll f[32][32];
ll x,y;
int k,b;
void init()
{
    f[0][0]=1;
    for(int i=1;i<=31;i++)
    {
        f[i][0]=f[i-1][0];
        for(int j=1;j<=i;j++)
            f[i][j]=f[i-1][j]+f[i-1][j-1];
    }
}
int calc(int x,int k)
{
    int tot = 0,ans  =0;
    for(int i=31;i>0;i--)
    {
        if(x&(1<<i))
        {
            ++tot;
            if(tot>k)break;
            x = x^(1<<i);
        }
        if((1<<(i-1))<=x)
            ans += f[i-1][k-tot];
    }
    if(tot+x==k)++ans;
    return ans;
}
int a[32];
void change(ll &x)
{
    int i,j;
    i=0;
    while(x)
    {
        a[i++]=x%b;
        x/=b;
    }
    int f = 0,tt=-1;
    for(j=i-1;j>=0;j--)
    {
        if(a[j]>1)
        {
            f=1;
            tt = j;break;
        }
    }
    if(f)
    {
        for(j=tt;j>=0;j--)
            a[j]=1;
    }

//    for(j=i-1;j>=0;j--)
//        cout<<a[j];
//        cout<<endl;
    ll sum=0;
    for(j=i-1;j>=0;j--)
        sum = sum*2+a[j];
    x=sum;
//    cout<<x<<endl;
}
int main()
{
    int i,j;
    init();
    while(scanf("%I64d%I64d",&x,&y)!=EOF)
    {
        scanf("%d%d",&k,&b);
        change(x);
        change(y);
        printf("%d\n",calc(y,k)-calc(x-1,k));
    }
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<ctime>
using namespace std;
const int N=5;
int a[3300000],pm;
int is(int i)
{
    int x=  i/32;
    int y = i%32;
    if(a[x]&(1<<y))return 1;
    return 0;
}
int prime[5861455];
#define ll unsigned int
ll sum[5861455];
void set(int i)
{
    int x= i/32;
    int y = i%32;
    a[x]|=(1<<y);
}
void init()
{
    int i,j;
    pm=0;
    for(i=2;i<=100000000;i++)
    {
        if(is(i)==0)
        {
            if(pm==0)sum[0]=i;
            else sum[pm]=sum[pm-1]*i;
            prime[pm++]=i;
            for(j=i+i;j<=100000000;j+=i)
                set(j);
        }
    }
}
ll ans;
long long n;
int judge(long long y,int x)
{
    long long s = 1;
    for(int i=1;i<=x;i++)
    {
        if(s*(long long)y>n)return 0;
        s = s*y;
    }
    return 1;
}
int bi(int x)
{
    int l = 0,r = 5761455;
    while(l<r)
    {
        int mid = (l+r)>>1;
        if(judge(prime[mid],x))r=mid;
        else l=mid+1;
    }
    if(l-1>=0)
    ans = ans*sum[l-1];
    return l-1;
}
int main()
{
    int i,j,t;
    init();
    scanf("%d",&t);
    while(t--)
    {
        cin>>n;
        for(i=1;i<=1;i++)
        {
            ans=1;
            cout<<i<<" "<<bi(i)<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}

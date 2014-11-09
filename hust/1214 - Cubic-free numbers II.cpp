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
#define ll long long
const int maxn = 2650000;
int num;
int a[maxn];
ll prime[maxn];
void init()
{
    num=0;
    int i,j;

    for(int i=2;i<maxn;i++)
    {
        if(a[i]==0)
        {
            prime[num++]=i*i*i;
            for(int j=i+i;j<maxn;j+=i)
                a[j]=1;
        }
    }
}
ll sum=0;
int end;
void dfs(int pos,ll x,int k,ll y,int end)
{ g
    if(x*prime[pos]<=y)
    {
        if(k&1)
            sum += y/(x*prime[pos]);
        else
            sum -= y/(x*prime[pos]);
    }
    else
        return;
    for(int i=pos+1;i<=end;i++)
    {
        dfs(i,x*prime[pos],k+1,y,end);
    }
}
ll f(ll x)
{
    int i,j;
    sum=0;
    end=0;
    for(i=0;i<num;i++)
    {
        if(prime[i]>x)break;
        end=i;
    }
    for(i=0;i<=end;i++)
    {
        dfs(i,1,1,x,end);
    }
    //cout<<x<<" "<<sum<<" "<<x-sum<<endl;
    return x-sum;
}
int main()
{
    int i,j,t;
    init();
    //cout<<num<<endl;
    scanf("%d",&t);
    while(t--)
    {
        ll l,r;
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",f(r-1)-f(l-1));
    }
    return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
#define ll __int64
const ll mod = 2520;
int a[20];
int s[100];
int sz;
ll dp[20][2555][50];
//int gcd(int a,int b)
//{
//    if(b==0)return a;
//    return gcd(b,a%b);
//}
int gcd(int a,int b)
{
    while(a%b)
    {
        int tmp=b;
        b=a%b;
        a=tmp;
    }
    return b;
}
int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}
//int lcm(int a,int b)
//{
//    int tmp = gcd(a,b);
//    return a*b/tmp;
//}
int find(int x)
{
    int l=0,r= sz-1;
    while(l<=r)
    {
        int mid = (l+r)>>1;
        //cout<<mid<<" "<<s[mid]<<endl;
        if(s[mid]<x)
            l = mid+1;
        else if(s[mid]==x)
            return mid;
        else
            r = mid-1;
    }
    return l;
}
ll dfs(int pos,int mod1,int lcm1,int limit)
{
    if(pos==-1)
    {
        if(mod1%s[lcm1]==0)
        {
            // cout<<mark<<" "<<sum<<endl;
            return 1;
        }
        else return 0;
    }
    if(limit==0&&dp[pos][mod1][lcm1]!=-1)
      return dp[pos][mod1][lcm1];
    int end = limit?a[pos]:9;
    ll sum =0;
    for(int i=0; i<=end; i++)
    {
        int mod2 = (mod1*10+i)%mod;
        int lcm2 = lcm1;
        if(i!=0)
        {
            lcm2 = lcm(s[lcm1],i);


            lcm2 = find(lcm2);
            //cout<<s[lcm1]<<" "<<i<<" "<<lcm2<<endl;
        }

        sum += dfs(pos-1,mod2,lcm2,limit&&(i==end));
    }
    if(limit==0)
      return dp[pos][mod1][lcm1] = sum;
    else return sum;
}
ll f(ll n)
{
    //if(n==0)return 0;
    int i,j=0;
    while(n)
    {
        a[j++]=n%10;
        n/=10;
    }
memset(dp,-1,sizeof(dp));
    ll sum=0;
    sum += dfs(j-1,0,0,1);
    return sum;
}
void init()
{
    sz=0;
    for(ll i=1; i<=mod; i++)
        if(mod%i==0)s[sz++]=i;
}
int main()
{
    int i,j,t;
    ll x,y;
    init();
//    for(i=0; i<sz; i++)
//        cout<<i<<"*"<<s[i]<<endl;
//    cout<<find(504)<<endl;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d%I64d",&x,&y);
       // cout<<f(y)<<endl;
        printf("%I64d\n",f(y)-f(x-1));
    }
}

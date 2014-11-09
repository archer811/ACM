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
int a[1000005];
ll prime[1000005];
int g;
int judge(ll n)
{
    int i;
    for(i=0;i<g&&prime[i]*prime[i]<=n;i++)
    {
        //if(n==2)cout<<prime[i]<<endl;
        if(prime[i]*prime[i]>n)break;
        if(n%prime[i]==0)
        {
           // cout<<prime[i]<<endl;
            return 0;
        }
    }
   // cout<<n<<endl;
    if(n!=1)return 1;
    return 0;
}
ll gcd(ll a,ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int i,j,t;
    g=0;

    for(i=2;i<=1000000;i++)
    {
        if(a[i]==0)
        {
           prime[g++]=i;
           for(j=i+i;j<=1000000;j+=i)
                a[j]=1;
        }
    }
    scanf("%d",&t);
    ll n;
    while(t--)
    {
        cin>>n;
        ll a = n,b = n+1;
        while(judge(a)==0)
        {
            a--;
        }
        while(judge(b)==0)
        {
            b++;
        }
        //cout<<a<<" "<<b<<endl;
        ll t1 = a-2;
        ll t2 = a*2;
        ll t3 = n-a+1,t4 = a*b;
        ll tmp = gcd(t1,t2);
        t1 /= tmp;t2 /= tmp;
        tmp = gcd(t3,t4);
        t3 /= tmp;t4 /= tmp;
        //cout<<t1<<" "<<t2<<"  "<<t3<<" "<<t4<<endl;
        ll g1 = (a-2)*b+(n-a+1)*2;
        ll g2 = 2*a*b;
        tmp = gcd(t1*t4+t2*t3,t2*t4);
        ll ansa = (t1*t4+t2*t3);
        ll ansb = t2*t4;
        tmp = gcd(g1,g2);
        cout<<g1/tmp<<"/"<<g2/tmp<<endl;
        //cout<<ansa/tmp<<"/"<<ansb/tmp<<endl;
    }
}

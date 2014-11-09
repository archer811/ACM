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
#define ll unsigned long long
ll a[20][20];
ll multi(ll a,ll b,ll mod)
{
    ll temp = a,sum = 0;
    while(b)
    {
        if(b&1) sum = (sum +  temp) % mod;
        temp = (temp + temp) % mod;
        b = b>>1;
    }
    return sum;
}

ll Modular_exponent(ll a,ll x,ll mod) // a ^ x mod MOD.
{
    ll t = a % mod,r = 1;
    while(x)
    {
        if(x & 1) r = multi(r,t,mod);
        t = multi(t,t,mod); x = x>>1;
    }
    return r;
}
//Carmicheal number: 561,41041,825265,321197185
bool Miller_Rabin(ll n) // 如果是素数，则返回1，否则返回0.
{
    ll time = 20;
    if(n < 2) return false;
    if(n == 2) return true;
    bool flag = false;
    for(ll k = 0;k <= time;++k)
    {
        flag = false;
        ll d = n - 1,r = 0,t,a = rand()%(n-2) + 2;
        while((d & 1) == 0)
        {
            d = d>>1;
            r++;
        }
        t = Modular_exponent(a,d,n);
        if(t == 1 || t == n-1) {flag = true;continue;}
        for(ll i = 1;i < r;i++)
        {
            t = multi(t,t,n);
            if(t == 1) {flag = false;return  flag;}
            if(t == n-1) {flag = true;break;}
        }
        if(!flag) break;
    }
    return flag;
}
int main()
{
    int i,j;
    int b,n;
    for(i=1;i<=16;i++)
    {
        a[i][0]=1;
        for(j=1;j<=16;j++)
            a[i][j]=a[i][j-1]*(ll)i;
    }
    while(scanf("%d%d",&b,&n)!=EOF)
    {
        ll sum=0;
        for(i=0;i<n;i++)
            sum += a[b][i];
        puts(Miller_Rabin(sum) ? "YES" : "NO");
    }
}

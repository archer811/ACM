#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
#define ll long long
ll n;
int m;
const int maxn = 2000006;
struct array
{
    ll q,w;
}s[maxn];
int cmp(array x,array y)
{
    return x.w>y.w;
}
ll judge(ll mid)
{
    ll sum;
    if(mid%2)sum = mid*(mid-1)/2+1;
    else sum = mid*(mid-1)/2+mid/2;
    return sum;
}
int main()
{
    int i,j,k;
    while(cin>>n>>m)
    {
        for(i=1;i<=m;i++)
            cin>>s[i].q>>s[i].w;
        sort(s+1,s+1+m,cmp);
        ll l=1,r = n,g;
        for(g= m;g>=1;g--)
        {
            if(n-judge(g)>=0)
            {
               // cout<<n<<"D"<<judge(g)<<endl;
                break;
            }
        }
        int sum=0;
        //cout<<g<<endl;
        for(ll ii = 1;ii<=m&&ii<=g;ii++)
            sum += s[ii].w;
        cout<<sum<<endl;
    }
}

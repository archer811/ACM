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
int a[66];
ll vis[66][12][2];
ll dfs(int pos,int status,int limit,int have)
{
    if(pos==-1)return (ll)have;
    if(limit==0&&vis[pos][status][have]!=-1)
        return vis[pos][status][have];
    int end = limit?a[pos]:9;
    ll sum=0;
    //cout<<end<<endl;
    for(int i=0;i<=end;i++)
    {
        //if(i==4)continue;
        if(status==4&&i==9)sum += dfs(pos-1,i,limit&&(i==end),1);
        else
        sum += dfs(pos-1,i,limit&&(i==end),have);
    }
    if(!limit)
    return vis[pos][status][have]=sum;
    return sum;
}
ll f(ll n)
{
    int i,j=0;
    ll N = n;
    while(n)
    {
        a[j++]=n%10;
        n/=10;
    }
    memset(vis,-1,sizeof(vis));
    return dfs(j-1,0,1,0);
}
int main()
{
    int i,j;
    ll n,m;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        cin>>n;
        cout<<f(n)<<endl;
    }
}

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
int a[20],len;
ll dp[20][11][20][20];
void output(int x)
{
    int g[20]={0},i,j=0;
    cout<<x;
    while(x)
    {
        g[j++]=x%10;x/=10;
    }
    for(i=j-1;i>=0;i--)
        cout<<g[i];
    cout<<endl;
}
void output(int x,int c)
{
    int g[20]={0},i,j=0;
    cout<<x;
    cout<<c;
    while(x)
    {
        g[j++]=x%10;x/=10;
    }
    for(i=j-1;i>=0;i--)
        cout<<g[i];
    cout<<endl;
}
int sz=0;
ll dfs(int pos,int limit,int have,int start,int status,int xx)
{
   // cout<<pos<<" "<<limit<<" "<<have<<" "<<start<<" "<<status<<endl;
    if(pos==-1)
    {
        //if(start==len)return 1;
        if(limit&&have)return 0;
//        cout<<xx<<"*"<<endl;
        sz++;
        return 1;
    }
    if(start!=len&&start-pos==pos+1)
    {
        if(limit&&have)return 0;
//        cout<<"*";
//        output(xx);
        sz++;
        //cout<<start<<" "<<pos<<" "<<xx<<endl;
        return 1;
    }
    if(start!=len&&start-pos==pos)
    {
        int end = limit?a[pos]:9;
        int end2 = end;
        if(limit&&have)end2=end2-1;
//        for(int i=0;i<=end2;i++)
//        {
//             cout<<"^";sz++;
//             output(xx,i);
//        }
        if(end2>=0)return end2+1;
        else return 0;
    }

    if(!limit&&dp[pos][status][have][start]!=-1)
    {
        return dp[pos][status][have][start];
    }

    int end = limit?a[pos]:9;
    ll sum=0;
    for(int i=0;i<=end;i++)
    {
        ll tmp = sum;
        if(start==len&&i!=0)
        {
            int weizhi = 0;
            int now = have;
            if(a[weizhi]<i)now=1;
            sum += dfs(pos-1,limit&&(i==end),now,pos,i,xx*10+i);
        }
        else if(start==len&&i==0)
        {
            sum += dfs(pos-1,limit&&(i==end),have,start,i,xx*10+i);
        }
        else
        {
            int weizhi = start-pos;
            int now = have;
            if(a[weizhi]<i)now=1;
            else if(a[weizhi]>i)now=0;
            sum += dfs(pos-1,limit&&(i==end),now,start,i,xx*10+i);
        }
        tmp = sum-tmp;
        //if(pos==3&&i==5&&limit)cout<<tmp<<"&"<<endl;
    }
    if(!limit)
        return dp[pos][status][have][start]=sum;
    return sum;
}
ll f(ll n)
{
    if(n<0)return 0;
    int i,j=0;
    while(n)
    {
        a[j++]=n%10;n/=10;
    }
    len=j;
    memset(dp,-1,sizeof(dp));
    return dfs(j-1,1,0,j,0,0);
}
int main()
{
    //freopen("out2.txt","w",stdout);
    int i,j,t;
    scanf("%d",&t);
    ll x,y;
    int cas=0;
    while(t--)
    {
        scanf("%lld%lld",&x,&y);
        if(x>y)swap(x,y);
        sz=0;
        //cout<<f(y)<<endl;
        printf("Case %d: %lld\n",++cas,f(y)-f(x-1));
        //cout<<sz<<"()"<<endl;
    }
}

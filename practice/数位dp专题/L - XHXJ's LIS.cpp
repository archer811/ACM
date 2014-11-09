#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
#define ll unsigned long long
int k;
ll l,r;
int a[32];
ll dp[32][1055][2];
int getsum(int x)
{
    int s=0;
    for(int i=0; i<=9; i++)
    {
        if((1<<i)&x)s++;
    }
    return s;
}
int getstate(int x, int s)
{
    for (int i = x; i < 10; ++i)
        if (s&(1<<i)) return (s^(1<<i))|(1<<x);
    return s|(1<<x);
}
ll dfs(int pos,int status,int state,int limit,int zh)
{
    if(pos==-1)
    {
        return getsum(state)==k;
    }
    if(!limit&&dp[pos][state][zh]!=-1)
    {
        return dp[pos][state][zh];
    }

    ll sum=0;
    int end = limit?a[pos]:9;
    for(int i=0; i<=end; i++)
    {
        int nextzh = (!(zh==0&&i==0));
        sum += dfs(pos-1,i,nextzh?getstate(i,state):0,limit&&(i==end),nextzh);
        /*
        if(zh==0)
        {
            if(i==0)
            {
                sum += dfs(pos-1,0,state,limit&&(i==end),0);
            }
            else
            {
                sum += dfs(pos-1,i,(1<<i),limit&&(i==end),1);
            }
        }
        else
        {

            sum += dfs(pos-1,i,getstate(i,state),limit&&(i==end),1);
        }*/
    }
    if(!limit)
        return dp[pos][state][zh]=sum;
    return sum;
}
ll f(ll n)
{
    int i,j=0;
    while(n)
    {
        a[j++]=n%10;
        n/=10;
    }
    return dfs(j-1,0,0,1,0);
}
int main()
{
    int i,j,t;
    //freopen("l.txt","w",stdout);
    scanf("%d",&t);
    int cas=0;
    memset(dp,-1,sizeof(dp));
    while(t--)
    {
        scanf("%I64d%I64d%d",&l,&r,&k);
        //f(r);
        //cout<<sz<<endl;
        //printf("%I64d %I64d",f(r),f(l-1));
        printf("Case #%d: %I64d\n",++cas,f(r)-f(l-1));
    }
}

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
int digit[25];
ll d[25][10][2];
ll dfs(int pos,int status,int limit,int mark)
{
    if(pos==-1)return 1;
    if(!limit&&d[pos][status][mark]!=-1)
        return d[pos][status][mark];
    int end = limit?digit[pos]:9;
    ll ans=0;
    int i,j;
    for(i=0;i<=end;i++)
    {
        if(mark&&(status-i>=2||i-status>=2))
        {
            //cout<<pos<<" * "<<i<<endl;
            ans += dfs(pos-1,i,limit&&(i==end),1);
        }
        else if(mark==0)
        {
            ans += dfs(pos-1,i,limit&&(i==end),i!=0);
            //cout<<pos<<"  "<<i<<" "<<ans<<endl;
        }
    }
    if(!limit)d[pos][status][mark]=ans;
    return ans;
}
ll f(ll n)
{
    int len=0;
    while(n)
    {
        digit[len++]=n%10;
        n/=10;
    }
    memset(d,-1,sizeof(d));
    return dfs(len-1,0,1,0);
}
int main()
{
    ll a,b;
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
        //cout<<a-1<<";1"<<endl;
        memset(digit,0,sizeof(digit));
        //cout<<f(0)<<endl;
        printf("%lld\n",f(b)-f(a-1));
    }
}

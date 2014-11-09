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
ll d[25][10][14];
int digit[25];
ll dfs(int pos,int status,int limit,int have,int res)
{
    if(pos==-1)return (have&&!res);
    if(!limit&&d[pos][status][res]!=-1)return d[pos][status][res];
    int end = limit?digit[pos]:9;
    ll ans=0;
    for(int i=0; i<=end; i++)
    {
        if(i==3&&status==1)
        {
            //have=1;
            ans += dfs(pos-1,i,limit&&(i==end),1,(res*10+i)%13);
        }
        else
        ans += dfs(pos-1,i,limit&&(i==end),have,(res*10+i)%13);
    }

    if(!limit)d[pos][status][res]=ans;
    return ans;
}
ll f(int n)
{
    int len=0;
    while(n)
    {
        digit[len++]=n%10;
        n/=10;
    }
    ll tmp = dfs(len-1,0,1,0,0);
    return tmp;
}
int main()
{
    int i,j,k,n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(d,-1,sizeof(d));
        cout<<f(n)<<endl;
    }
}

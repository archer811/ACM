#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define ll __int64
ll x,y;
int k,b;
const ll inf = ((ll)1)<<31;
ll a[11][32];
int ans =0;
void dfs(int num,int from,int index,ll sum)
{
    if(num==k)
    {
        if(sum>=x&&sum<=y)ans++;
        return;
    }
    for(int i=from;i<32;i++)
    {
        if(a[index][i]==-1)break;
        dfs(num+1,i+1,index,sum+a[index][i]);
    }
}
int main()
{
    int i,j;
    memset(a,-1,sizeof(a));
    for(i=2;i<=10;i++)
    {
        a[i][0]=1;
        for(j=1;j<=31;j++)
        {
            ll tmp = a[i][j-1]*(ll)i;
            if(tmp>inf)break;
            a[i][j]=tmp;
        }
    }
    while(scanf("%I64d%I64d",&x,&y)!=EOF)
    {
        scanf("%d%d",&k,&b);
        ans =0;
        dfs(0,0,b,0);
        printf("%d\n",ans);
        //cout<<ans<<endl;
    }
}

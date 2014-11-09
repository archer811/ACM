#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<functional>
#include<bitset>
using namespace std;
int n,m,c,d;
char s[105][11];
#define ll long long
ll dp[2][1025][22];
const ll mod = 1000000007;
void dfs(int han,int hehe,int pos,int fro,int now,int num,ll oo)
{
    if(num>d)return;
    if(pos==m)
    {

        (dp[hehe][now][num] += oo)%=mod;
        // cout<<hehe<<"*"<<now<<" "<<num<<" "<<dp[hehe][now][num]<<endl;
        return ;
    }
    if(((1<<pos)&fro)==0)
    {
        //if(han==2)cout<<"!"<<endl;
        if(((1<<pos)&now)==0)
        {
            dfs(han,hehe,pos+1,fro,now|(1<<pos),num,oo);
            if(pos>=1&&(((1<<(pos-1))&now)==0))
                dfs(han,hehe,pos+1,fro,now|(1<<pos)|(1<<(pos-1)),num+1,oo);

            //dfs(han,hehe,pos+1,fro,now,num+1,oo);
        }

        dfs(han,hehe,pos+1,fro,now,num+1,oo);

    }
    else
    {
        dfs(han,hehe,pos+1,fro,now,num,oo);
//cout<<"<<="<<pos<<" "<<now<<endl;
        if(((1<<pos)&now)==0)
        {

            if(pos>=1&&(((1<<(pos-1))&now)==0))
            {
                //cout<<"<<"<<(now|(1<<pos)|(1<<(pos-1)))<<endl;
                dfs(han,hehe,pos+1,fro,now|(1<<pos)|(1<<(pos-1)),num,oo);
            }
        }
    }
}
int main()
{
    int i,j,k;
    while(scanf("%d%d%d%d",&n,&m,&c,&d)!=EOF)
    {
        for(i=1; i<=n; i++)
            scanf("%s",s[i]);
        memset(dp,0,sizeof(dp));
        int mm = (1<<m)-1;
        dp[0][mm][0]=1;
        int t1,t=0;
        for(i=1; i<=n+1; i++)
        {
            int sum=0;
            t1 = t^1;
            //cout<<t1<<"!!!!!!!!!!"<<t<<endl;
            for(j=0; j<m&&i<=n; j++)
            {
                if(s[i][j]=='0')sum+=(1<<j);
            }
            if(i==n+1)sum=mm;
            for(j=0; j<=mm; j++)
            {
                for(int k=0; k<=d; k++)
                {
                    if(dp[t][j][k]!=0)
                    {
                        // cout<<t<<" "<<j<<" "<<k<<endl;
                        dfs(i,t1,0,j,sum,k,dp[t][j][k]);
                    }
                }
            }
            for(j=0; j<=mm; j++)
            {
                for(k=0; k<=d; k++)
                {
                    //cout<<dp[i%2][j][k]<<"|"<<j<<" "<<k<<endl;
                    dp[t][j][k]=0;
                }
            }
            t = t1;
        }
        ll sum=0;
        for(i=c; i<=d; i++)
        {
            if(dp[t1][mm][i]!=0)
                sum = (sum+dp[t1][mm][i])%mod;
        }
        printf("%lld\n",sum);
    }
}

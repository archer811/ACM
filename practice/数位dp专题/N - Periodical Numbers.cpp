#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
#define ll __int64
ll l,r;
int a[70];
vector<int>g[70];
ll dp[71][2][71][71][2];
vector<int>ans;
ll dfs(int pos,int start,int status,int num,int lenth,int limit,int have,int first1,int first2,int xx)
{
    //if(start==4&&lenth==1)
      //cout<<pos<<" "<<num<<" "<<lenth<<" "<<have<<endl;
    if(num==lenth)
    {
        //if(have==0)cout<<xx<<endl;
        return have==0;
    }
    if(dp[pos][status][start][lenth][limit]!=-1)
        return dp[pos][status][start][lenth][limit];
    int end = limit?a[pos]:1;
    ll sum=0;
    for(int i=0; i<=end; i++)
    {
        if(pos==start&&i==0)continue;
        int have2=have;
        int f1=first1,f2=first2;
        if(limit)
        {
            for(int j=pos; j>=0; j-=lenth)
            {
                if(a[j]>i)f1=max(f1,j);
                if(a[j]<i)f2=max(f2,j);
            }
            if(f1>f2 || (f1==f2&&f1==-1))
                have2=0;
            else have2=1;
        }

        //if(start==5&&lenth==2)
        //    cout<<i<<"*"<<limit<<" "<<f1<<" "<<f2<<" "<<have2<<" "<<sum<<endl;
        sum += dfs(pos-1,start,i,num+1,lenth,limit&&(i==end),have2,f1,f2,xx*2+i);
    }
    return dp[pos][status][start][lenth][limit]=sum;
    return sum;
}
int Gcd(int a,int b)
{
    if(b==0)return a;
    return Gcd(b,a%b);
}
ll f(ll n)
{
    int i,j,len=0;
    while(n)
    {
        a[len++]=n%2;
        n/=2;
    }
    //cout<<len<<endl;
    memset(dp,-1,sizeof(dp));
    ll sum=0;
    for(i=len-1; i>=0; i--)
    {
        for(j=0; j<g[i+1].size(); j++)
        {
            //cout<<i<<" ** "<<g[i+1][j]<<endl;
            if(i!=len-1)
                sum += dfs(i,i,0,0,g[i+1][j],0,0,-1,-1,0);
            else
                sum += dfs(i,i,0,0,g[i+1][j],1,0,-1,-1,0);
        }
    }
    sum  = 0;
    for(i=len-1;i>=0;i--)
    {
        ans.clear();
        for(j=0;j<g[i+1].size();j++)
        {
            int flag=0;
            for(int k=j+1;k<g[i+1].size();k++)
            {
                if(g[i+1][k]%g[i+1][j]==0){flag=1;break;}
            }
            if(flag==0)
                ans.push_back(g[i+1][j]);
        }
//        cout<<i<<":"<<endl;
//        for(j=0;j<ans.size();j++)
//        {
//            cout<<ans[j]<<" ";
//        }
//        cout<<endl;
        int M = ans.size();
        int tt=0;
        if(i==len-1)tt=1;
        if(M==1)
        {
            sum += dp[i][0][i][ans[0]][tt];
            //cout<<sum<<"()"<<endl;
            continue;
        }
        M = 1<<M;

        for(j=1;j<M;j++)
        {
            int num=0;
            ll tmp=0;
            int gcd=-1;
            int mark=0;
            for(int k=0;k<ans.size();k++)
            {
                if((1<<k)&j)
                {
                    if(mark==0)
                    {
                        mark=1;
                        gcd  =  ans[k];
                        tmp = dp[i][0][i][ans[k]][tt];
                        num ++;
                        continue;
                    }
                    num++;
                    tmp += dp[i][0][i][ans[k]][tt];
                    gcd = Gcd(gcd,ans[k]);
                }
            }
            if(gcd==-1)continue;
            //sum += tmp;
            //cout<<gcd<<"##################"<<endl;
            int ok =1;
            if(num%2)
                sum += dp[i][0][i][gcd][tt];
            else
            {
                sum -= dp[i][0][i][gcd][tt];ok = -1;
            }

            //cout<<i<<" "<<j<<"*"<<sum<<endl;
        }
        //cout<<sum<<"*"<<endl;
    }
    return sum;
}
int main()
{
    int i,j;
    for(i=1; i<70; i++)
    {
        g[i].clear();
        for(j=1; j<i; j++)
        {
            if(i%j==0)
                g[i].push_back(j);
        }
        //cout<<g[i].size()<<endl;
    }
    while(scanf("%I64d%I64d",&l,&r)!=EOF)
    {
        //cout<<f(r)<<endl;
       // printf("%I64d %I64d\n",f(r),f(l-1));
          printf("%I64d\n",f(r)-f(l-1));
    }
}

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
int n,m;
#define ll long long
char s[20];
struct array
{
    ll D,T;
    int kind;
}g[333];
vector<array>v[20];
int flag[333];
int Max[50005];
ll dp[15][50005][3];
int f(char s[])
{
    if(strcmp(s,"Weapon")==0)return 11;
    if(strcmp(s,"Shield")==0)return 12;
    if(strcmp(s,"Two-Handed")==0)return 13;
    if(strcmp(s,"Head")==0)return 1;
    if(strcmp(s,"Shoulder")==0)return 2;
    if(strcmp(s,"Neck")==0)return 3;
    if(strcmp(s,"Torso")==0)return 4;
    if(strcmp(s,"Hand")==0)return 5;
    if(strcmp(s,"Wrist")==0)return 6;
    if(strcmp(s,"Waist")==0)return 7;
    if(strcmp(s,"Legs")==0)return 8;
    if(strcmp(s,"Feet")==0)return 9;
    if(strcmp(s,"Fingers")==0)return 10;
}
ll _max(ll a,ll b)
{
    if(a>b)return a;
    return b;
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(dp,-1,sizeof(dp));
        int D,T;
        int index=0;
        dp[0][0][0]=0;
        for(i=1;i<=14;i++)
            v[i].clear();
        for(i=1;i<=n;i++)
        {
            scanf("%s%lld%lld",s,&g[i].D,&g[i].T);
            g[i].kind=f(s);
            flag[i]=0;
        }

        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                //if(g[i].kind!=13&&g[j])
                if(g[i].kind!=10&&g[i].kind==g[j].kind&&g[i].D<g[j].D&&g[i].T<g[j].T)flag[i]=1;
                if(g[i].kind!=10&&g[i].kind==g[j].kind&&g[i].D>g[j].D&&g[i].T>g[j].T)flag[j]=1;
            }
        }
        for(i=1;i<=n;i++)
        {
            if(flag[i])continue;
            int tmp = g[i].kind;
            v[tmp].push_back(g[i]);
        }

        for(i=1;i<=9;i++)
        {
            for(j=0;j<=m+1;j++)
            {
                Max[j]=0;
                if(dp[i-1][j][0]==-1&&dp[i-1][j][1]==-1)
                    dp[i][j][0]=-1;
                else if(dp[i-1][j][0]!=-1&&dp[i-1][j][1]!=-1)
                    dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1];
                else if(dp[i-1][j][0]!=-1)
                    dp[i][j][0]=dp[i-1][j][0];
                else
                    dp[i][j][0]=dp[i-1][j][1];
            }
            for(j=0;j<v[i].size();j++)
            {
                array gg = v[i][j];
                Max[gg.D]=_max(Max[gg.D],gg.T);
            }
        }

        //printf("%lld\n",Max);
    }
    return 0;
}

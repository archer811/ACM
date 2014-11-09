#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
#define ll long long
ll dp[2][51005][3];
char s[20];
struct array
{
    ll D,T;
    int kind;
}g[333],pre[20],ans[333];
int f(char s[])
{
    if(strcmp(s,"Weapon")==0)return 1;
    if(strcmp(s,"Shield")==0)return 2;
    if(strcmp(s,"Two-Handed")==0)return 3;
    if(strcmp(s,"Head")==0)return 4;
    if(strcmp(s,"Shoulder")==0)return 5;
    if(strcmp(s,"Neck")==0)return 6;
    if(strcmp(s,"Torso")==0)return 7;
    if(strcmp(s,"Hand")==0)return 8;
    if(strcmp(s,"Wrist")==0)return 9;
    if(strcmp(s,"Waist")==0)return 10;
    if(strcmp(s,"Legs")==0)return 11;
    if(strcmp(s,"Feet")==0)return 12;
    if(strcmp(s,"Fingers")==0)return 13;
    return 0;
}
ll _max(ll a,ll b)
{
    if(a>b)return a;
    return b;
}
int cmp(array a,array b)
{
    if(a.kind==b.kind&&a.D==b.D)return a.T>b.T;
    else if(a.kind==b.kind)return a.D>b.D;
    return a.kind<b.kind;
}
int flag[333];
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(dp,-1,sizeof(dp));
        int D,T;
        for(i=1;i<=14;i++)
            pre[i].D=pre[i].T=-1;
        int index=0;
        dp[1][0][0]=0;
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
                if(g[i].kind!=13&&g[i].kind==g[j].kind&&g[i].D<g[j].D&&g[i].T<g[j].T)flag[i]=1;
                if(g[i].kind!=13&&g[i].kind==g[j].kind&&g[i].D>g[j].D&&g[i].T>g[j].T)flag[j]=1;
            }
        }

        int g2=1;
        for(i=1;i<=n;i++)
        {
            if(flag[i])continue;
            ans[g2++]=g[i];
        }

//        for(i=1;i<=n;i++)
//        {
//            cout<<i<<" "<<g[i].D<<" "<<g[i].T<<" "<<g[i].kind<<endl;
//        }
        for(i=1; i<g2; i++)
        {
            D = ans[i].D;
            T = ans[i].T;
            for(j=0; j<=m+1; j++)
            {
                dp[index][j][0]=dp[index^1][j][0];
                dp[index][j][1]=dp[index^1][j][1];
                dp[index][j][2]=dp[index^1][j][2];
            }
            int tmp;
            if(ans[i].kind==1||ans[i].kind==2)tmp=1;
            else if(ans[i].kind==3)tmp=2;
            else tmp=0;
            if(tmp==0)
            {
                for(j=m+1; j>=0; j--)
                {
                    if(j+T>m)
                    {
                        if(dp[index^1][j][0]!=-1)
                        dp[index][m+1][0]=_max(dp[index][m+1][0],dp[index^1][j][0]+D);
                        if(dp[index^1][j][1]!=-1)
                        dp[index][m+1][1]=_max(dp[index][m+1][1],dp[index^1][j][1]+D);
                        if(dp[index^1][j][2]!=-1)
                        dp[index][m+1][2]=_max(dp[index][m+1][2],dp[index^1][j][2]+D);
                    }
                    else
                    {
                        if(dp[index^1][j][0]!=-1)
                        dp[index][j+T][0]=_max(dp[index][j+T][0],dp[index^1][j][0]+D);
                        if(dp[index^1][j][1]!=-1)
                        dp[index][j+T][1]=_max(dp[index][j+T][1],dp[index^1][j][1]+D);
                        if(dp[index^1][j][2]!=-1)
                        dp[index][j+T][2]=_max(dp[index][j+T][2],dp[index^1][j][2]+D);
                    }

                }
            }
            else if(tmp==1)
            {
                for(j=m+1; j>=0; j--)
                {
                    if(j+T>m)
                    {
                        if(dp[index^1][j][0]!=-1)
                        dp[index][m+1][1]=_max(dp[index][m+1][1],dp[index^1][j][0]+D);
                        if(dp[index^1][j][1]!=-1)
                        dp[index][m+1][1]=_max(dp[index][m+1][1],dp[index^1][j][1]+D);
                    }
                    else
                    {
                        if(dp[index^1][j][0]!=-1)
                        dp[index][j+T][1]=_max(dp[index][j+T][1],dp[index^1][j][0]+D);
                        if(dp[index^1][j][1]!=-1)
                        dp[index][j+T][1]=_max(dp[index][j+T][1],dp[index^1][j][1]+D);
                    }
                }
            }
            else if(tmp==2)
            {
                for(j=m+1; j>=0; j--)
                {
                    if(j+T>m)
                    {
                        if(dp[index^1][j][0]!=-1)
                        dp[index][m+1][2]=_max(dp[index][m+1][2],dp[index^1][j][0]+D);
                        if(dp[index^1][j][2]!=-1)
                        dp[index][m+1][2]=_max(dp[index][m+1][2],dp[index^1][j][2]+D);
                    }
                    else
                    {
                        if(dp[index^1][j][0]!=-1)
                        dp[index][j+T][2]=_max(dp[index][j+T][2],dp[index^1][j][0]+D);
                        if(dp[index^1][j][2]!=-1)
                        dp[index][j+T][2]=_max(dp[index][j+T][2],dp[index^1][j][2]+D);
                    }

                }
            }
            index^=1;
        }
        index^=1;
        ll Max=-1;
//        cout<<index<<endl;
        for(i=m; i<=m+1; i++)
        {
            if(dp[index][i][0]>Max)Max=dp[index][i][0];
            if(dp[index][i][1]>Max)Max=dp[index][i][1];
            if(dp[index][i][2]>Max)Max=dp[index][i][2];
            //cout<<dp[index][i][0]<<" "<<dp[index][i][1]<<" "<<dp[index][i][2]<<endl;
        }
        printf("%lld\n",Max);
        //cout<<Max<<endl;
    }
    return 0;
}

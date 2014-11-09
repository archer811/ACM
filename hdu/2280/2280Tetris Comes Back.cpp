#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int n,c;
char s[10005][6];
const int m = (1<<5)-1;
int dp[10005][m+10];
int mark[m+5][m+5];
const int inf = 0x3fffffff;
void dfs(int pos,int fro,int now,int num)
{
    //cout<<pos<<" "<<fro<<" "<<now<<endl;
    if(pos==5)
    {
        if(num<mark[fro][now])
            mark[fro][now]=num;
        return ;
    }
    int t11 = -1,t12 = -1,t21 = -1, t22 = -1;
    t11 = ((1<<pos)&fro);
    if(pos+1<5)
    t12 = ((1<<(pos+1))&fro);
    t21 = ((1<<pos)&now);
    if(pos+1<5)
    t22 = ((1<<(pos+1))&now);
    if(t11==0&&t12==0&&t22==0)
    {
        dfs(pos+2,fro,now|(1<<(pos+1)),num);
        if(t21==0)
        {
            dfs(pos+2,fro,now|(1<<(pos+1))|(1<<pos),num+1);
        }
    }
    if(t11==0&&t12==0&&t21==0)
    {
        dfs(pos+2,fro,now|(1<<(pos)),num);
        if(t22==0)
        {
            dfs(pos+2,fro,now|(1<<(pos+1))|(1<<pos),num+1);
        }
    }
    if(t11==0&&t21==0&&t22==0)
        dfs(pos+1,fro,now|(1<<(pos+1))|(1<<pos),num);
    if(t12==0&&t21==0&&t22==0)
    {
        if(t11>=1)
            dfs(pos+2,fro,now|(1<<(pos+1))|(1<<pos),num);
    }
    if(t11==0&&t21==0)
        dfs(pos+1,fro,now|(1<<pos),num);
    if(t11>=1)dfs(pos+1,fro,now,num);
    if(t11>=1&&t21==0)dfs(pos+1,fro,now|(1<<pos),num+1);
    if(t11>=1&&t21==0&&t22==0)
        dfs(pos+1,fro,now|(1<<(pos+1))|(1<<pos),num);
}
int main()
{
    //freopen("out.txt","w",stdout);
    int i,j,k;
    for(i=0;i<=m;i++)
        for(j=0;j<=m;j++)
           mark[i][j]=inf;
    for(i=0;i<=m;i++)
        dfs(0,i,0,0);
    //cout<<mark[31][31]<<endl;
    while(scanf("%d%d",&n,&c)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%s",s[i]);
        for(i=0;i<=n+1;i++)
            for(j=0;j<=m;j++)
              dp[i][j]=inf;
        dp[0][m]=0;
        for(i=1;i<=n+1;i++)
        {
            int sum=0;
            for(j=0;j<5;j++)
            {
                if(s[i][j]=='1')
                    sum += (1<<j);
            }
            if(i==n+1)sum=m;
            for(j=0;j<=m;j++)
            {
                if(dp[i-1][j]>=inf)continue;
                for(k=0;k<=m;k++)
                {
                    if(k&sum)continue;
                    int tmp = dp[i-1][j]+mark[j][k];
                    if(dp[i][(k|sum)]>tmp)
                        dp[i][(k|sum)]=tmp;
//                    cout<<i<<" "<<j<<" "<<k<<" "<<(k|sum)<<" "
//                    <<dp[i][(k|sum)]<<endl;
                }
            }
        }
        if(dp[n+1][m]<=c)
            puts("YES");
        else puts("NO");
    }
}

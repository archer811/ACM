#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;
int n,m,w;
const double inf=100000.00;
double dp[1200][120];
int pre[1200][120];
double a[120][120],b[120][120];
int we[1200];
int flag=0;
void dfs(int now,int tmp)
{
    if(now==0)
    {
        return;
    }
    dfs(now-1,pre[now][tmp]);
    if(flag==0)
        printf("%d",tmp),flag=1;
    else printf(" %d",tmp);
}
stack<int >q1;
int main()
{
    int i,j,k,T;
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d%d%d",&n,&m,&w);
        for(i=1; i<=n; i++)
            scanf("%d",&we[i]);
        for(i=0; i<m; i++)
        {
            for(j=0; j<m; j++)
                scanf("%lf",&a[i][j]);
        }
        for(i=0; i<m; i++)
        {
            for(j=0; j<w; j++)
                scanf("%lf",&b[i][j]);
        }
        dp[0][0]=1;
        for(k = 1; k<=n; k++)
        {
            for(j=0; j<m; j++)
            {
                double tmp = 0;
                int from=0;
                for(i=0; i<m; i++)
                {
                    if(dp[k-1][i]*a[i][j]*b[j][we[k]]>tmp)
                    {
                        tmp = dp[k-1][i]*a[i][j]*b[j][we[k]];
                        from = i;
                    }
                }
                dp[k][j]=tmp;
                pre[k][j]=from;
            }

            int flag=0;
            for(int j=0; j<m; j++)
            {
                if(dp[k][j]>inf)
                {
                    flag=1;
                    break;
                }
            }
            if(!flag)
            {
                for(int j=0; j<m; j++)
                {
                    dp[k][j]*=inf;
                }
            }

        }
        int ans = 0;
        double M =0.0;
        for(i=0; i<m; i++)
        {
            if(dp[n][i]>M)
            {
                M = dp[n][i];
                ans = i;
            }
        }
        int day = n;
        q1.push(ans);
        ans=pre[day][ans];
        int num=day-1;
        while(num>0)
        {
            q1.push(ans);
            ans=pre[num][ans];
            num--;
        }
        int flag2=0;
        while(!q1.empty())
        {
            int t1=q1.top();
            q1.pop();
            if(flag2) printf(" %d",t1);
            else
            {
                flag2=1;
                printf("%d",t1);
            }
        }
        puts("");
    }
}


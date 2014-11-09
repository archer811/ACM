#include<cstdio>
#include<cstring>
#include<stack>
#include<iostream>
#define M 1008
#define N 108
#define inf 1000000.0
using namespace std;
int day,n,w;
double dp[M][N];
double place[N][N];
double weather[N][N];
int w_boy[M];
int pre[M][N];
stack<int >q1;
int main()
{
    int cas;
    while(~scanf("%d",&cas))
    {
        while(cas--)
        {
            scanf("%d%d%d",&day,&n,&w);
            for(int i=1; i<=day; i++) scanf("%d",&w_boy[i]);
            for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%lf",&place[i][j]);
            for(int i=0; i<n; i++) for(int j=0; j<w; j++) scanf("%lf",&weather[i][j]);
            for(int i=0; i<=day; i++) for(int j=0; j<n; j++) dp[i][j]=0;
            dp[0][0]=1.00;
            for(int i=0; i<day; i++)
            {
                for(int j=0; j<n; j++)
                {
                    double tmp=dp[i][j];
                    for(int k=0; k<n; k++)
                    {
                        double t1=place[j][k];
                        double t2=weather[k][w_boy[i+1]];
                        if(dp[i+1][k]<tmp*t1*t2)
                        {
                            dp[i+1][k]=tmp*t1*t2;
                            pre[i+1][k]=j;
                        }
                    }
                }
                int flag=0;
                for(int j=0; j<n; j++)
                {
                    if(dp[i+1][j]>inf)
                    {
                        flag=1;
                        break;
                    }
                }
                if(!flag)
                {
                    for(int j=0; j<n; j++)
                    {
                        dp[i+1][j]*=inf;
                    }
                }
            }
            double tmax=0.0;
            int flag=0;
            for(int i=0; i<n; i++)
            {
                if(dp[day][i]>tmax)
                {
                    tmax=dp[day][i];
                    flag=i;
                }
            }
            q1.push(flag);
            flag=pre[day][flag];
            int num=day-1;
            while(num)
            {
                q1.push(flag);
                flag=pre[num][flag];
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
    return 0;
}

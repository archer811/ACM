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
int dp[41][129][129];
int num[130];
int judge(int a,int b,int c)
{
    int i,j;
    int flag=0;
    if(n==1)
    {
        if(((a&1)==0)&&((b&1)==0)&&((c&1)==0))return 0;
        return 1;
    }
    int x = n-1;

    if(((a&1)==0)&&((b&1)==0)&&((c&1)==0)&&((b&2)==0))return 0;
    //cout<<((a&1)==0)<<" "<<(b&1==0)<<" "<<(c&1==0)<<" "<<(b&2==0)<<endl;
    if(((a&(1<<x))==0)&&((b&(1<<x))==0)&&((c&(1<<x))==0)&&((b&(1<<(x-1)))==0))
        return 0;
    for(i=1;i<n-1;i++)
    {
        if(((a&(1<<i))==0)&&((b&(1<<i))==0)&&((c&(1<<i))==0)&&
           ((b&(1<<(i-1)))==0)&&((b&(1<<(i+1)))==0))
        return 0;
    }
    return 1;
}
int main()
{
    int i,j,k,t;
    for(i=1; i<130; i++)
    {
        if(i&1)num[i]=num[i/2]+1;
        else num[i]=num[i/2];
    }
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n>m)swap(n,m);
        memset(dp,-1,sizeof(dp));
        int M = (1<<n);
        for(i=0; i<M; i++)
            dp[1][i][0]=num[i];
        for(i=2; i<=m; i++)
        {
            for(j=0; j<M; j++)
            {
                for(k=0; k<M; k++)
                {
                    for(t=0; t<M; t++)
                    {
                        if(dp[i-1][k][t]==-1)continue;
                        if(judge(t,k,j))
                        {

                            int tmp = dp[i-1][k][t]+num[j];


                            if(dp[i][j][k]==-1||dp[i][j][k]>tmp)
                                dp[i][j][k]=tmp;

//                            cout<<t<<" "<<k<<" "<<j<<" "<<i<<"  "<<dp[i-1][k][t]<<
//                            "  "<<tmp<<"  "<<dp[4][1][0]<<endl;
                        }
                    }
                }
            }
        }
//        cout<<dp[4][1][0]<<endl;
        int ans = n*m+1;
        for(i=0;i<M;i++)
        {
            for(j=0;j<M;j++)
            {
                if(judge(i,j,0))
                {
                    if(dp[m][j][i]!=-1&&dp[m][j][i]<ans)
                        ans=dp[m][j][i];
//                    cout<<i<<" "<<j<<" "<<dp[m][j][i]<<endl;
                }
            }
        }
        //cout<<"1"<<endl;
        cout<<n*m-ans<<endl;
        //printf("%d\n",n*m-ans);
    }
}

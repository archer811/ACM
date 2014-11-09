#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define ll __int64
int F[10];
ll dp[11][11][5000];
ll s[5000];
int b[11];
int f(int x)
{
    int i,j=0,a[10];
    while(x)
    {
        a[j++]=x%10;
        x/=10;
    }
    int sum =0;
    for(i=j-1;i>=0;i--)
        sum += F[i]*a[i];
    return sum;
}
int main()
{
    int i,j,k,T,A,B;
    F[0]=1;
    for(i=1;i<=9;i++)
        F[i]=F[i-1]*2;
    for(i=0;i<=9;i++)
        dp[1][i][i]=1;
    int sum=0;
    for(i=2;i<=9;i++)
    {
        sum = sum+F[i-1]*9;
        for(j=0;j<=sum;j++)
            s[j]=0;
        for(j=0;j<=sum;j++)
        {
            for(k=0;k<=9;k++)
                s[j]+=dp[i-1][k][j];
        }
        for(j=0;j<=sum;j++)
        {
            for(k=0;k<=9;k++)
            {

                dp[i][k][j+k*F[i-1]]+=s[j];
            }
        }
    }
    for(i=1;i<=9;i++)
    {
        for(j=0;j<=9;j++)
        {
            for(k=1;k<5000;k++)
                dp[i][j][k]+=dp[i][j][k-1];
        }
        for(k=0;k<5000;k++)
            for(j=1;j<=9;j++)
              dp[i][j][k]+=dp[i][j-1][k];
    }
    scanf("%d",&T);
    int cas=0;
    while(T--)
    {
        //cout<<dp[3][0][5]<<endl;
        scanf("%d%d",&A,&B);
        int g = f(A);
        k =0 ;
        while(B)
        {
            b[k++]=B%10;
            B/=10;
        }
        ll sum =0;
        //cout<<g<<"fff"<<endl;
        for(i=k-1;i>=0;i--)
        {
            int tmp;
            if(i==0)tmp=b[i];
            else tmp = b[i]-1;
            if(tmp<0)continue;
            if(g>=0)
            sum += dp[i+1][tmp][g];
            g = g-F[i]*b[i];
        }
        printf("Case #%d: ",++cas);
        cout<<sum<<endl;
    }
}

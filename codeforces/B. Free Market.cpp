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
int c[100];
int dp[580005];
int main()
{
    int i,j,n,d;
    while(scanf("%d%d",&n,&d)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        int sum=0;
        for(i=1;i<=n;i++)
            scanf("%d",&c[i]),sum+=c[i];
        dp[0]=1;
        for(i=1;i<=n;i++)
        {
            for(j=sum-c[i];j>=0;j--)
            {
                if(dp[j])dp[j+c[i]]++;
            }
        }
        int now=0,nn=0;
        while(1)
        {
            int flag=0;
            for(i=now+d;i>now;i--)
            {
                if(dp[i]){flag=1;break;}
            }
            if(flag==0)break;
            //cout<<i<<endl;
            now=i;nn++;

        }
        cout<<now<<" "<<nn<<endl;
    }
    return 0;
}

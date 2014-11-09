#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
char s[200006],a[12][12],ans;
const int inf = 0x3fffffff;
int dp[200006][12];
int main()
{
    int i,j,k,n;
    while(scanf("%s",s)!=EOF)
    {
        int len  =strlen(s);
        scanf("%d",&n);
        int M = inf;
        for(i=len-1;i>=0;i--)
            s[i+1]=s[i+1+len]=s[i];
//        for(i=1;i<=len*2;i++)
//            cout<<s[i];
//        cout<<endl;
        for(i=1;i<=n;i++)
        {
            scanf("%s",a);
            int len1 = strlen(a);
            for(j=len1-1;j>=0;j--)
                a[j+1]=a[j];
            if(len<=20)
            {

                ---------------------------------------------------------------------------------
            }
            else
            {
                dp[0][0]=0;
                for(j=1;j<=len;j++)
                {
                    for(k=1;k<=len1;k++)
                    {
                        if(s[j]==a[k])
                            dp[j][k]=dp[j-1][k-1]+1;
                        else dp[j][k]=max(dp[j-1][k],dp[j][k-1]);
                    }
                }
                int tmp = len1-dp[len][len1];
                if(M>tmp)
                {
                    M=tmp;
                    ans=i;
                }
            }
        }
    }
}

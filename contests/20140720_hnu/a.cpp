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
#define ll long long
const ll mod = 1000000007;
char s[100005];
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s+1);
        int len = strlen(s+1);
        int flag=0;
        ll ans=1;
        for(i=1;i<=len;i++)
        {
            if(s[i]=='?')flag=1;
        }
        if(flag==0)
        {
            printf("1\n");continue;
        }
        for(i=1;i<=len;i++)
        {
            if(s[i]=='?')
            {
                int l = i,r=i;
                for(j=i;j<=len;j++)
                {
                    if(s[j]=='?')r=j;
                    else break;
                }
                if(l==1||r==len)
                {
                    ans = ans*1;
                }
                else
                {
                    if(s[l-1]==s[r+1])ans=ans*1;
                    else ans = ans*(ll)(r-l+2);
                }

                ans = ans%mod;
                i=r;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

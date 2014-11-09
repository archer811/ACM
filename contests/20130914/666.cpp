#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define ll __int64
const ll mod = (ll)1000000007;
ll dp[100005][2];
char s[100005],t[100005];
char se[100005],te[100005];
int main()
{
    int i,j,k,T;
    scanf("%d",&T);
    int cas=0;
    while(T--)
    {
        scanf("%s%s",s,t);
        int len = strlen(s);
        memset(dp,0,sizeof(dp));
        for(i=0; i<len; i++)
            se[i]=s[i],te[i]=t[i];
        dp[0][0]=1;
        dp[0][1]=0;
        int ans =0;
        for(i=1; i<=len; i++)
        {
            if(s[i-1]=='?'&&t[i-1]=='?')
            {
                dp[i][0]+=dp[i-1][1]+dp[i-1][0];
                dp[i][1]+=dp[i-1][0]+dp[i-1][1];
            }
            else if((s[i-1]=='?'&&t[i-1]=='0')||(s[i-1]=='0'&&t[i-1]=='?'))
            {
                dp[i][0]+=dp[i-1][0];
                dp[i][1]+=dp[i-1][1];
            }
            else if((s[i-1]=='?'&&t[i-1]=='1')||(s[i-1]=='1'&&t[i-1]=='?'))
            {
                dp[i][0]+=dp[i-1][1];
                dp[i][1]+=dp[i-1][0];
            }
            else if((s[i-1]=='0'&&t[i-1]=='1')||(s[i-1]=='1'&&t[i-1]=='0'))
            {
                dp[i][0]=0;
                dp[i][1]=0;
                ans++;
            }
            else if(s[i-1]=='0'&&t[i-1]=='0')
            {
                dp[i][0]+=dp[i-1][0];
                dp[i][1]+=dp[i-1][1];
            }
            else if(s[i-1]=='1'&&t[i-1]=='1')
            {
                dp[i][0]+=dp[i-1][1];
                dp[i][1]+=dp[i-1][0];
            }
            dp[i][0]%=mod;
            dp[i][1]%=mod;
        }



        printf("Case #%d:\n",++cas);
        if(ans>1)
        {
            puts("Impossible");
            continue;
        }
        ll sum =0;
        int mark =-1;
        if(s[len-1]=='?'&&t[len-1]=='?')
        {
            sum += dp[len-1][0]+dp[len-1][1];
            if(dp[len-1][0])
            {
                se[len-1]='0';
                te[len-1]='1';
                mark = 0;
            }
            if(dp[len-1][1])
            {
                se[len-1]='1';
                te[len-1]='0';
                mark = 1;
            }
        }
        else if((s[len-1]=='?'&&t[len-1]=='0')||(s[len-1]=='1'&&t[len-1]=='0')||(s[len-1]=='1'&&t[len-1]=='?'))
        {
            sum += dp[len-1][1];
            if(dp[len-1][1])
            {
                se[len-1]='1';
                te[len-1]='0';
                mark = 1;
            }
        }
        else if((s[len-1]=='?'&&t[len-1]=='1')||(s[len-1]=='0'&&t[len-1]=='1')||(s[len-1]=='0'&&t[len-1]=='?'))
        {
            sum += dp[len-1][0];
            if(dp[len-1][0])
            {
                se[len-1]='0';
                te[len-1]='1';
                mark = 0;
            }

        }
        sum %= mod;


        s[len]=t[len]='0';
        int flag=-1,mark2=-1;
        for(i=len; i>=0; i--)
        {
            if(s[i]=='1'||t[i]=='1')break;
            if(i-2>=0&&s[i-1]!='0'&&t[i-1]!='0')
            {
                se[i-1]=te[i-1]='1';
                se[i]=te[i]='0';
                if(s[i-2]=='?'&&t[i-2]=='?')
                {
                    sum += dp[i-2][0]+dp[i-2][1];
                    if(dp[i-2][0])
                    {
                        se[i-2]='0';
                        te[i-2]='1';
                        mark2 = 0;
                        flag = i-2;
                    }
                    if(dp[i-2][1])
                    {
                        se[i-2]='1';
                        te[i-2]='0';
                        mark2 = 1;
                        flag = i-2;
                    }
                }
                else if((s[i-2]=='?'&&t[i-2]=='0')||(s[i-2]=='1'&&t[i-2]=='0')||(s[i-2]=='1'&&t[i-2]=='?'))
                {
                    sum += dp[i-2][1];
                    se[i-2]='1';
                    te[i-2]='0';
                    mark2 = 1;
                    flag = i-2;
                }
                else if((s[i-2]=='?'&&t[i-2]=='1')||(s[i-2]=='0'&&t[i-2]=='1')||(s[i-2]=='0'&&t[i-2]=='?'))
                {
                    sum += dp[i-2][0];
                    se[i-2]='0';
                    te[i-2]='1';
                    mark2 = 0;
                    flag = i-2;
                }
            }
            sum %= mod;
        }

        if(sum==0)
            puts("Impossible");
        else if(sum>1)
            printf("Ambiguous %I64d\n",sum);
        else
        {
            //cout<<mark<<endl;
            if(mark!=-1)
            {
                int ss=0;
                j=-1;
                for(i=len-2; i>=0; i--)
                {
                    if(s[i]=='?'&&t[i]=='?')
                    {
                        j=i;
                    }
                    else if(s[i]=='?')
                    {
                        se[i]=t[i];
                        te[i]=t[i];
                        if(se[i]=='1')ss++;
                    }
                    else if(t[i]=='?')
                    {
                        se[i]=s[i];
                        te[i]=s[i];
                        if(se[i]=='1')ss++;
                    }
                    else if(s[i]=='1')
                        ss++;

                }
                //cout<<j<<" "<<ss<<endl;
                if(mark==0)
                {
                    if(ss%2)se[j]=te[j]='1';
                    else se[j]=te[j]='0';
                }
                else
                {
                    if(ss%2)se[j]=te[j]='0';
                    else se[j]=te[j]='1';
                }
            }
            else
            {
                int ss=0;
                j=-1;
                for(i=flag+2;i<len;i++)
                {
                    se[i]=te[i]='0';
                }
                for(i=flag-1; i>=0; i--)
                {
                    if(s[i]=='?'&&t[i]=='?')
                    {
                        j=i;
                    }
                    else if(s[i]=='?')
                    {
                        se[i]=t[i];
                        te[i]=t[i];
                        if(se[i]=='1')ss++;
                    }
                    else if(t[i]=='?')
                    {
                        se[i]=s[i];
                        te[i]=s[i];
                        if(se[i]=='1')ss++;
                    }
                    else if(s[i]=='1')ss++;

                }

                if(mark2==0)
                {
                    if(ss%2)se[j]=te[j]='1';
                    else se[j]=te[j]='0';
                }
                else if(mark2==1)
                {
                    if(ss%2)se[j]=te[j]='0';
                    else se[j]=te[j]='1';
                }
            }
            for(i=0; i<len; i++)
                printf("%c",se[i]);
            puts("");
            for(i=0; i<len; i++)
                printf("%c",te[i]);
            puts("");
        }
    }
}

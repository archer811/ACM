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
char s[105],t[105];
int dp[105][105];
int dfs(int l,int r)
{
    int i,j;
    if(dp[l][r]!=-1)return dp[l][r];
    if(r<l)return 0;
    if(l==r)return dp[l][r]=1;
    int sum=(r-l+1);
    for(i=l;i<r;i++)
    {
        if(s[i]!=t[i])break;
        for(j=r;j>=i;j--)
        {
            if(s[j]!=t[j])break;
            sum = min(sum,dfs(i,j));
        }
    }

//cout<<l<<"  "<<r<<"  "<<sum<<endl;
    for(i=0;i<26;i++)
    {
        int tmp = 1;
        int start=-1,end=-1;
        for(j=l;j<=r;j++)
        {
            if(t[j]-'a'==i)
            {
                if(start!=-1&&end!=-1)
                {

                    tmp += dfs(start,end);
                    start=-1;end=-1;
                }
                else if(start!=-1)
                {
                    tmp += dfs(start,j-1);
                    start=-1;end=-1;
                }
                continue;
            }
            if(start==-1)
            {
                start=j;continue;
            }
        }
//if(l==0&&r==11&&i==2)
//    cout<<start<<" "<<end<<"  "<<dfs(start,r)<<endl;
        if(start!=-1&&end==-1&&start!=l)
            tmp += dfs(start,r);
        if(start==l&&end==-1)continue;
        if(tmp<sum)
            sum=tmp;
    }
    //
    for(i=l;i<r;i++)
        if(dfs(l,i)+dfs(i+1,r)<sum)
            sum=dfs(l,i)+dfs(i+1,r);
    return dp[l][r]=sum;
}
int main()
{
    int i,j;
    while(scanf("%s%s",s,t)!=EOF)
    {
        memset(dp,-1,sizeof(dp));
        int len = strlen(s);
        printf("%d\n",dfs(0,len-1));
    }
}

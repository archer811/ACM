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
char s[105][105];
char tp[105];
int num[105];
ll fib[105];
int mark[105];
const ll mod = 1000000007;
int g[105];
int next[105];
int to[105];
ll sum=0;
int bigmark=0;
void dfs(int u,int fa)
{
    mark[u]=1;
    if(u==-1)return;
    sum++;
    dfs(next[u],u);
}
int main()
{
    int i,j,t,n,k;
    scanf("%d",&t);
    int cas=0;
    fib[0]=1;
    for(i=1; i<=100; i++)
        fib[i]=fib[i-1]*(ll)i%mod;
    while(t--)
    {
        int flag=0;
        scanf("%d",&n);
        memset(next,-1,sizeof(next));
        memset(to,-1,sizeof(to));
        for(i=0; i<n; i++)
            mark[i]=0,g[i]=0;
        for(i=0; i<n; i++)
        {
            scanf("%s",tp);
            int len = strlen(tp);
            s[i][0]=tp[0];
            num[i]=1;
            for(j=1; j<len; j++)
            {
                if(tp[j]==tp[j-1])continue;
                s[i][num[i]++]=tp[j];
            }
            if(num[i]==1)
            {
                mark[i]=1;
                g[s[i][0]-'a']++;
            }
            for(j=0; j<num[i]; j++)
            {
                if(flag)break;
                for(k=j+1; k<num[i]; k++)
                {
                    if(s[i][j]==s[i][k])
                    {
                        flag=1;
                        break;
                    }
                }
            }
        }

        for(i=0; i<n&&flag==0; i++)
        {
            if(mark[i])continue;
            for(j=0; j<n&&flag==0; j++)
            {
                if(i==j)continue;
                if(mark[j])continue;
                for(k=1; k<num[i]-1; k++)
                {
                    for(int ff=0; ff<num[j]; ff++)
                    {
                        if(s[i][k]==s[j][ff])
                        {
                            flag=1;
                            break;
                        }
                    }
                }
            }
        }
        for(i=0; i<n&&flag==0; i++)
        {
            for(j=0; j<26; j++)
            {
                if(g[j]==0)continue;
                for(k=1; k<num[i]-1; k++)
                {
                    if(s[i][k]==(char)(j+'a'))
                    {
                        flag=1;
                        break;
                    }
                }
            }
        }
        for(i=0; i<n&&flag==0; i++)
        {
            if(mark[i])continue;
            for(j=0; j<n&&flag==0; j++)
            {
                if(i==j)continue;
                if(mark[j])continue;
                if(s[i][num[j]-1]==s[j][0])
                {
                    if(next[i]==-1)next[i]=j;
                    else flag=1;
                    if(to[j]==-1)to[j]=i;
                    else flag=1;
                }
            }
        }
        printf("Case #%d: ",++cas);
        if(flag)
        {
            puts("0");
            continue;
        }
        ll ans=1;
        ll f=0;
        for(i=0; i<26; i++)
        {
            cout<<i<<"()"<<g[i]<<endl;
            if(g[i])
                ans = ans*(ll)g[i]%mod,f++;
        }cout<<f<<"*"<<endl;

        for(i=0; i<n; i++)
        {
            if(mark[i])continue;
            if(to[i]==-1)
            {
                sum=0;
                bigmark=0;
                dfs(i,-1);
                f++;
            }
        }
        for(i=0;i<n;i++)
        {
            if(mark[i])continue;
            sum=0;
            bigmark=0;
            dfs(i,-1);
            if(bigmark)ans = ans*(ll)sum%mod;
            f++;
        }
        cout<<f<<endl;
        ans = ans*f%mod;
        printf("%lld\n",ans);
    }
    return 0;
}

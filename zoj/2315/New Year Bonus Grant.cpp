#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 500100;
int head[maxn],tot;
struct array
{
    int to,next;
}edge[maxn];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int dp[maxn];
void dfs(int u)
{
    int i,j;
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        dp[v]=dp[u]+1;
        dfs(v);
    }
}
int mark[maxn],f[maxn];
struct  xy
{
    int dp,index;
}s[maxn];
int cmp(xy a,xy b)
{
    return a.dp>b.dp;
}
int main()
{
    int i,j,casenum;
    int n;
    while(scanf("%d",&casenum)!=EOF)
    {
        for(int g=0;g<casenum;g++)
        {
            scanf("%d",&n);
            memset(head,-1,sizeof(head));
            tot=0;
            memset(dp,0,sizeof(dp));
            for(i=2;i<=n;i++)
            {
                scanf("%d",&j);
                f[i]=j;
                add(j,i);
            }
            memset(mark,0,sizeof(mark));
            dfs(1);
            for(i=1;i<=n;i++)
            {
                s[i].dp=dp[i];s[i].index=i;
            }
            sort(s+1,s+1+n,cmp);
            for(i=1;i<=n;i++)
            {
                if(mark[s[i].index]==-1)continue;
                if(s[i].index==1)continue;
                if(mark[f[s[i].index]]==-1)continue;
                mark[s[i].index]=1;
                mark[f[s[i].index]]=-1;
            }
            int sum=0;
            for(i=1;i<=n;i++)
                if(mark[i]==1)sum++;
            printf("%d\n",sum*1000);
            int flag=0;
            for(i=1;i<=n;i++)
            {
                if(mark[i]!=1)continue;
                if(flag==0)printf("%d",i);
                else printf(" %d",i);
                flag=1;
            }
            puts("");
        }
    }
    return 0;
}

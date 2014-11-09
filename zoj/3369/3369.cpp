#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int n,h,s,p,m;
struct array
{
    int si,pi,mi;
}in[55];
int vis[55];
char ans[55];
bool ok;
void dfs(int health,int strength,int power,int points,int step)
{
    int i,j;
    if(ok)return;
    if(step==0)
    {
        for(i=1;i<=n;i++)
            printf("%c",ans[i]);
        printf("\n");
        ok = true;
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(ok)return;
        if(vis[i])continue;
        if(strength>=in[i].si)
        {
            int t = max(2*in[i].si-strength,0);
            if(health-t<=0)continue;
            ans[i]='D';
            vis[i]=1;
            dfs(health-t,strength+1,power,points,step-1);
            vis[i]=0;
        }
        if(ok)return;
        if(power>=in[i].pi&&points>=in[i].mi)
        {
            ans[i]='E';
            vis[i]=1;
            dfs(health,strength,power+1,points-in[i].mi,step-1);
            vis[i]=0;
        }
    }
}
int main()
{
    int i,j;
    while(scanf("%d%d%d%d%d",&n,&h,&s,&p,&m)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++)
        {
            scanf("%d%d%d",&in[i].si,&in[i].pi,&in[i].mi);
        }
        ok = false;
        dfs(h,s,p,m,n);
        if(ok==false)
        {
            puts("UNLUCKY");
        }
    }
}

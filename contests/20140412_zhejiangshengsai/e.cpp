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
const int maxn = 1005;
int pre[maxn],now[maxn];
char s[maxn][maxn];
int vis[maxn][maxn];
int map[maxn][maxn];
vector<int>ans;
int siz[maxn],v[maxn],n,vv[maxn];
void out(int x)
{
    if(x<=n)printf("R%d",x);
    else printf("C%d",x-n);
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1; i<=n; i++)
            scanf("%s",s[i]+1);
        memset(vis,0,sizeof(vis));
        int n1=0,n2=0;
        memset(map,0,sizeof(map));
        memset(vv,0,sizeof(vv));
        while(1)
        {
            n2=0;
            int ff=0;
            for(i=1; i<=n; i++)
            {
                ff=0;
                for(j=1; j<=n; j++)
                {
                    if(vis[i][j])continue;
                    if(vis[i][j]==0&&s[i][j]=='X')ff=1;
                    else break;
                }
                if(j==n+1&&ff)
                    now[n2++]=i;
            }
            int x=0,nownow=n2;
            for(j=1; j<=n; j++)
            {
                ff=0;
                for(i=1; i<=n; i++)
                {
                    if(vis[i][j])continue;
                    if(vis[i][j]==0&&s[i][j]=='O')ff=1;
                    else break;
                }
                if(i==n+1&&ff)
                    now[n2++]=j+n;
            }
            if(n2==0)break;
            while(x<nownow)
            {
                for(j=1; j<=n; j++)
                    vis[now[x]][j]=1;
                x++;
            }
            while(x<n2)
            {
                for(i=1; i<=n; i++)
                    vis[i][now[x]-n]=1;
                x++;
            }
            for(i=0; i<n2; i++)
            {
                for(j=0; j<n1; j++)
                {
                    map[now[i]][pre[j]]=1;
                    vv[now[i]]=1;vv[pre[j]]=1;
                }
            }
            for(i=0; i<n2; i++)
                pre[i]=now[i];
            n1=n2;
            n2=0;
        }
        int judge=0;
        for(i=1; i<=n&&judge==0; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(vis[i][j]==0)
                {
                    judge=1;
                    break;
                }
            }
        }
        if(judge)
        {
            puts("No solution");
            continue;
        }
        ans.clear();
        for(i=1; i<=n*2; i++)
        {
            siz[i]=0;
            v[i]=0;
            for(j=1; j<=n*2; j++)
            {
                if(map[j][i])siz[i]++;
            }
            //cout<<i<<" "<<siz[i]<<endl;
        }
        while(1)
        //for(int gg=0;gg<10;gg++)
        {
            int ff=0;
            for(i=1; i<=2*n; i++)
            {
                if(vv[i]==0)continue;
                //cout<<v[i]<<" "<<siz[i]<<endl;
                if(v[i]==0&&siz[i]==0)
                {
                    ff=i;break;
                }
            }
            if(ff==0)break;
            v[i]=1;
            for(i=1;i<=n*2;i++)
            {
                if(map[ff][i])
                {
                    siz[i]--;
                }
            }
            //cout<<ff<<endl;
            ans.push_back(ff);
        }
        for(i=0;i<ans.size();i++)
        {
            if(i==0)
            {
                out(ans[i]);
            }
            else
            {
                printf(" ");
                out(ans[i]);
            }
        }
        puts("");
    }
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int t,k,l;
const int nodenum = 105*70;
const int sig = 70;
int ch[nodenum][sig];
int val[nodenum];
int sz;
int fail[nodenum];
void init()
{
    sz = 1;
    memset(ch[0],0,sizeof(ch[0]));
}
int idx(char s)
{
    if(s>='a'&&s<='z')return s-'a';
    else if(s>='A'&&s<='Z')return 26+s-'A';
    else return 52+s-'0';
}
void insert(char *s)
{
    int len = strlen(s);
    int i,j;
    int u = 0;
    for(i=0; i<len; i++)
    {
        j = idx(s[i]);
        if(ch[u][j]==0)
        {
            memset(ch[sz],0,sizeof(ch[sz]));
            val[sz]=0;
            ch[u][j]=sz++;
        }
        u = ch[u][j];
    }
    val[u]=1;
}
char s[32];
double ans[77];
int vis[nodenum][105];
double dp[nodenum][105];
double dfs(int u,int step)
{
    if(step==l)return 1.0;
    if(vis[u][step])return dp[u][step];

    double sum=0;
    for(int i=0; i<62; i++)
    {
         if(ans[i]>0)
        {
            //cout<<ch[u][i]<<"()"<<val[ch[u][i]]<<endl;
            if(val[ch[u][i]]==0)
            {
                sum += ans[i]*dfs(ch[u][i],step+1)*1.0;
            }
        }
    }
    vis[u][step]=1;
    return dp[u][step]=sum;
}
queue<int>q;
void AC()
{
    while(!q.empty())q.pop();
    int i,j;
    for(i=0; i<62; i++)
    {
        if(ch[0][i])
        {
            q.push(ch[0][i]);
            fail[ch[0][i]]=0;
        }
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(i=0; i<62; i++)
        {
            if(ch[u][i])
            {
                int v = fail[u];
                q.push(ch[u][i]);
                while(v&&ch[v][i]==0)
                    v = fail[v];
                fail[ch[u][i]]=ch[v][i];
                val[ch[u][i]]|=val[fail[u]];
            }
            else
                ch[u][i]=ch[fail[u]][i];
        }
    }
}
void getFail()
{
    fail[0] = 0;
    // 初始化队列
    for(int c = 0; c < 62; c++)
    {
        int u = ch[0][c];
        if(u)
        {
            fail[u] = 0;
            //cout<<u<<"("<<endl;
            q.push(u);
        }
    }
    // 按BFS顺序计算fail
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int c = 0; c < 62; c++)
        {
            if(ch[u][c])
            {
                q.push(ch[u][c]);
//                int v = fail[u];
//                while(v && !ch[v][c]) v = fail[v];
//                fail[ch[u][c]] = ch[v][c];
//                //last[u] = val[f[u]] ? f[u] : last[f[u]];
//                val[ch[u][c]]|=val[fail[ch[u][c]]];//计算禁止结点
//                continue;
                fail[ch[u][c]]=ch[fail[u]][c];
                val[ch[u][c]]|=val[ch[fail[u]][c]];
            }
            else ch[u][c]=ch[fail[u]][c];

        }
    }
}
int main()
{
    int i,j,n;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        init();
        scanf("%d",&k);
        for(i=1; i<=k; i++)
        {
            scanf("%s",s);
            insert(s);
        }
        getFail();
        scanf("%d",&n);
        //cout<<sz<<"*"<<endl;
        memset(ans,0,sizeof(ans));
        for(i=1; i<=n; i++)
        {
            scanf("%s",s);
            int tmp = idx(s[0]);
            double d;
            scanf("%lf",&d);
            ans[tmp] = d;
        }
        scanf("%d",&l);
        memset(vis,0,sizeof(vis));
        memset(dp,0,sizeof(dp));
        printf("Case #%d: %.6f\n",++cas,dfs(0,0));
        //  printf("%lf\n",dfs(0,0));
    }
}

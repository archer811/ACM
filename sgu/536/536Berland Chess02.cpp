#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
typedef long long LL;

const int N = 15;
const int inf = 1<<28;
using namespace std;
typedef pair<int,int> PII;
int n,m;
char maz[N][N],s[N][N];
int rn,pos[N];
int dp[N][1<<N];
int dx[]= {1,-1,0,0,1,-1,-1,1};
int dy[]= {0,0,-1,1,1,-1,1,-1};

void input()
{
    rn=0;
    for(int i=0; i<n; i++)
    {
        scanf("%s",maz[i]);
        for(int j=0; j<m; j++)
        {
            if(maz[i][j]!='.') pos[rn++]=i*m+j;
        }
    }
}

void init(int k,int mask)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++) s[i][j]=maz[i][j];
    }
    int nx[]= {1,-1,1,-1},ny[]= {1,1,-1,-1};
    int fx[]= {1,2,1,2,-1,-2,-1,-2},fy[]= {2,1,-2,-1,2,1,-2,-1};
    for(int i=0; i<rn; i++)
    {
        int x=pos[i]/m,y=pos[i]%m;
        if((!(mask&(1<<i)))||i==k)
        {
            s[x][y]='.';
            continue;
        }
        if(maz[x][y]=='*') continue;
        if(maz[x][y]=='K')
        {
            for(int j=0; j<8; j++)
            {
                int kx=x+fx[j],ky=y+fy[j];
                if(kx>=0&&kx<n&&ky>=0&&ky<m) s[kx][ky]='#';
            }
        }
        else if(maz[x][y]=='B')
        {
            for(int j=0; j<4; j++)
            {
                int kx=x+nx[j],ky=y+ny[j];
                while(kx>=0&&kx<n&&ky>=0&&ky<m)
                {
                    s[kx][ky]='#';
                    if(maz[kx][ky]!='.') break;
                    kx+=nx[j],ky+=ny[j];
                }
            }
        }
        else if(maz[x][y]=='R')
        {
            for(int j=0; j<4; j++)
            {
                int kx=x+dx[j],ky=y+dy[j];
                while(kx>=0&&kx<n&&ky>=0&&ky<m)
                {
                    s[kx][ky]='#';
                    if(maz[kx][ky]!='.') break;
                    kx+=dx[j],ky+=dy[j];
                }
            }
        }
    }
//    for(int i=0;i<n;i++) puts(s[i]);
}

int dis[N][N],vis[N][N];
bool inque[N][1<<N];

void bfs(int k,int st)
{
    init(k,st);
    queue<PII> q;
    memset(vis,0,sizeof(vis));
    int x=pos[k]/m,y=pos[k]%m;
    vis[x][y]=1,dis[x][y]=0;
    q.push(PII(x,y));
    while(!q.empty())
    {
        PII tmp=q.front();
        q.pop();
        x=tmp.first,y=tmp.second;
        for(int i=0; i<8; i++)
        {
            int kx=x+dx[i],ky=y+dy[i];
            if(kx>=0&&kx<n&&ky>=0&&ky<m&&s[kx][ky]!='#'&&!vis[kx][ky])
            {
                dis[kx][ky]=dis[x][y]+1,vis[kx][ky]=1;
                if(s[kx][ky]=='.') q.push(PII(kx,ky));
            }
        }
    }
}

void DP()
{
    queue<PII> q;
    memset(dp,-1,sizeof(dp));
    memset(inque,0,sizeof(inque));
    for(int i=0; i<rn; i++)
    {
        int x=pos[i]/m,y=pos[i]%m;
        if(maz[x][y]=='*')
        {
            q.push(PII(i,(1<<rn)-1));
            dp[i][(1<<rn)-1]=0;
            inque[i][(1<<rn)-1]=1;
            break;
        }
    }
    while(!q.empty())
    {
        PII tmp=q.front();
        q.pop();
        int k=tmp.first,st=tmp.second;
        if(st==(1<<k)) continue;
//        printf("%d %d %d %d %d\n",pos[k]/m,pos[k]%m,k,st,dp[k][st]);
        bfs(k,st);
        for(int i=0; i<rn; i++)
        {
            if(i==k) continue;
            int x=pos[i]/m,y=pos[i]%m,nst=st^(1<<k);
            if((st&(1<<i))&&vis[x][y])
            {
                if(dp[i][nst]==-1||dp[i][nst]>dp[k][st]+dis[x][y])
                {
                    dp[i][nst]=dp[k][st]+dis[x][y];
                    if(!inque[i][nst])
                    {
                        q.push(PII(i,nst));
                        inque[i][nst]=1;
                    }
                }
            }
        }
    }
}

void get()
{
    int res=-1;
    for(int i=0; i<rn; i++)
    {
        if(dp[i][1<<i]!=-1&&(res==-1||res>dp[i][1<<i])) res=dp[i][1<<i];
    }
    printf("%d\n",res);
}

int main()
{
    //  freopen("in","r",stdin);
    while(scanf("%d%d",&n,&m)>0)
    {
        input();
        if(rn==1)
        {
            puts("0");
            continue;
        }
        DP();
        get();
    }
    return 0;
}

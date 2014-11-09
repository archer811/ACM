#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
#ifdef __int64
typedef __int64 ll;
#else
typedef long long ll;
#endif
/*
const int maxn = 400005;
int head[maxn],tot;
struct Edge
{
    int to,next;
}edge[maxn];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}*/
const int maxn = 1000006;
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
char s[33][33];
int f[33][33];
int n,m;
int go[][2]={-1,0,1,0,0,1,0,-1};
int ok(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m)return 1;
    return 0;
}
int v[33];
int del[33];
int vis[33],num[33];
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {

        memset(f,0,sizeof(f));
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%s",&s[i]);
        int M = -1;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(s[i][j]-'A'>M)
                    M=s[i][j]-'A';
                for(int k=0;k<4;k++)
                {
                    int x = go[k][0]+i;
                    int y = go[k][1]+j;
                    if(ok(x,y))
                    {
                        if(s[x][y]!=s[i][j])
                        {
                            f[s[x][y]-'A'][s[i][j]-'A']=f[s[i][j]-'A'][s[x][y]-'A']=1;
                        }
                    }
                }
            }
        }
        for(i = 0;i <= M; i++)
        {
            scanf("%d",&v[i]);
        }
        int value;
        scanf("%d",&value);
        for(i = 0; i <= M; i ++ )
        {
            int s=1;
            for(j = 0; j <= M; j ++ )
            {
                if(f[i][j])s++;
            }
            num[i] = s;
            del[i] = 0;
            vis[i]  = 0;
        }
        ll ans=-1;
        for(i = 0;i <= M; i ++ )
        {
            int flag=-1;
            ll sum=-1;
            for(j=0;j<=M;j++)
            {
                if(vis[j])continue;
                int tmp = 0;
                for(int k=0;k<=M;k++)
                {
                    if(vis[k])continue;
                    if(f[j][k])
                    {
                        tmp += v[k]/num[k];
                        //cout<<j<<" "<<k<<" "<<v[k]<<"()"<<num[k]<<endl;
                    }
                }
                tmp += v[j]-del[j];
               // cout<<j<<" "<<tmp<<endl;
                if(flag==-1||tmp<sum)
                {
                    sum=tmp;
                    flag=j;
                }
            }
            //cout<<endl;
            //cout<<flag<<endl;
            if(flag==-1)break;
            ans = max(ans,sum);
            for(j=0;j<=M;j++)
            {
                if(vis[j])continue;
                if(f[flag][j])
                {
                    num[j]--;
                    del[j]+=v[j]/num[j];
                }
            }
            vis[flag]=1;
        }
        if(ans>value)puts("Human");
        else puts("Saruman");
        //printf("%lld\n",ans);
    }
    return 0;
}

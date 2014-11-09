#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<map>
#include<sstream>
using namespace std;
int n,m;
char s[3000006];
map<string,int>M;
const int inf = 0x3fffffff;
int tot;
int w[2222];
const int maxn = 2222;
int head[maxn],e;
struct array
{
    int to,next;
}edge[maxn*4];
void add(int u,int v)
{
    //cout<<u<<"*"<<v<<endl;
    edge[e].to=v;
    edge[e].next=head[u];
    head[u]=e++;
}
int num[maxn];
int d[maxn][maxn];
void dfs(int u,int fa)
{
    int i,j,k;
    num[u]=1;
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        dfs(v,u);
        num[u] += num[v];
//        cout<<u<<"^*&^*&"<<v<<endl;
        for(j=tot;j>=0;j--)
        {
            if(d[u][j]>=inf)continue;
            for(k=0;k<=tot;k++)
            {
                if(d[v][k]>=inf)continue;
//                cout<<u<<" ** "<<v<<" "<<j<<
//                " "<<k<<" "<<d[u][j]<<" "<<d[v][k]<<endl;

                d[u][j+k]=min(d[u][j+k],d[u][j]+d[v][k]);
            }
        }
    }
    d[u][num[u]]=min(d[u][num[u]],w[u]);
}
int in[maxn];
int main()
{
    int i,j,k;
    char tg[12];
    while(scanf("%s",tg)!=EOF)
    {
        M.clear();
        n=0;
        if(tg[0]=='#')break;
        int len = strlen(tg);
        for(i=0;i<len;i++)
            n = n*10+tg[i]-'0';

        scanf("%d",&m);//cout<<n<<" "<<m<<endl;
        string line,str,now;
        memset(w,0,sizeof(w));
        tot=1;
        e=0;
        memset(head,-1,sizeof(head));
        for(i=0;i<maxn;i++)
        {
            for(j=0;j<maxn;j++)
            {
                d[i][j]=inf;
            }
        }
        for(i=0;i<maxn;i++)
            d[i][0]=0,in[i]=0;
        getchar();
        for(int tt=0;tt<n;tt++)
        {
            getline(cin,line);
            istringstream stream(line);
            j=0;
            while(stream>>str)
            {
                j++;
                //if(str=="#")continue;
                if(j!=2&&M[str]==0&&str!="#")
                {
                    M[str]=tot++;
                   // cout<<str<<" ((  "<<tot<<endl;
                }
                if(j==1)now=str;
                if(j==2)
                {
                    int sum=0;
                    k = str.length();
                    for(int g=0;g<k;g++)
                        sum = sum*10+str[g]-'0';
                    w[M[now]]=sum;
                }
                if(j>=3)
                {
                    int t1 = M[now],t2 = M[str];
                    in[t2]++;
                    add(t1,t2);
                    add(t2,t1);
                }
            }
            if(j==1&&now=="#")break;
        }
        for(i=1;i<tot;i++)
        {
            if(in[i]==0)add(0,i),add(i,0);
        }
        dfs(0,-1);
        int ans=inf;
        for(i=m;i<tot;i++)
           ans = min(ans,d[0][i]);
        cout<<ans<<endl;
    }
}

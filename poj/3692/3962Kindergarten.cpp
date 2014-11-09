#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 555;
int n = 100;
vector<int>g[maxn];
int from[maxn],tot;
bool use[maxn];
bool match(int x)
{
    for(int i=0;i<g[x].size();i++)
        if(!use[g[x][i]])
        {
            use[g[x][i]]=true;
            if(from[g[x][i]]==-1||match(from[g[x][i]]))
            {
                from[g[x][i]]=x;
                return true;
            }
        }
    return false;
}
int hungary()
{
    tot=0;
    memset(from,255,sizeof(from));
    for(int i=1;i<=n;i++)
    {
        memset(use,0,sizeof(use));
        if(match(i))++tot;
    }
    return tot;
}
int _map[405][405];
int main()
{
    int G,B,M,i,j,k,a,b;
    int cas=0;
    while(scanf("%d%d%d",&G,&B,&M)!=EOF)
    {
        if(G==0&&B==0&&M==0)break;
        for(i=1;i<=G+B;i++)
            for(j=i+1;j<=G+B;j++)
               _map[i][j]=_map[j][i]=1;
        for(i=1;i<=G+B;i++)
            g[i].clear();
        while(M--)
        {
            scanf("%d%d",&a,&b);
            b+=G;
            _map[a][b]=0;
        }
        for(i=1;i<=G;i++)
        {
            for(j=G+1;j<=G+B;j++)
            {
                if(_map[i][j])
                    g[i].push_back(j);
            }
        }
        n = G;
        printf("Case %d: %d\n",++cas,G+B-hungary());
    }
}

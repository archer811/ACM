#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 5555;
int n;
vector<int>g[maxn];
int from[maxn],tot;
bool use[maxn];
bool match(int x)
{
    for(int i=0;i<g[x].size();i++)
    {
        if(!use[g[x][i]])
        {
            use[g[x][i]]=true;
            if(from[g[x][i]]==-1||match(from[g[x][i]]))
            {
                from[g[x][i]]=x;
                return true;
            }
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
        if(match(i))
            tot++;
    }
    return tot;
}
char s[1005][1005];
int main()
{
    int r,c,i,j,k;
    while(scanf("%d%d",&r,&c)!=EOF)
    {
        for(i=1;i<=r+c;i++)
           g[i].clear();
        for(i=0;i<r;i++)
        {
            scanf("%s",s[i]);
            for(j=0;j<c;j++)
            {
                if(s[i][j]=='*')
                {
                    g[i+1].push_back(j+1+r);
                    g[j+1+r].push_back(i+1);
                }
            }
        }
        n = r;
        cout<<hungary()<<endl;
    }
}

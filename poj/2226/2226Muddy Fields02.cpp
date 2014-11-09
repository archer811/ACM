#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 5555;
vector<int>g[maxn];
int from[maxn],tot;
bool use[maxn];
int n;
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
int hungry()
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
int mapx[1005][1005],mapy[1005][1005];
int main()
{
    int r,c,i,j,k;
    while(scanf("%d%d",&r,&c)!=EOF)
    {
        for(i=1;i<=5000;i++)
           g[i].clear();
        memset(mapx,0,sizeof(mapx));
        memset(mapy,0,sizeof(mapy));
        for(i=0;i<r;i++)
        {
            scanf("%s",s[i]);
        }
        int t1 = 1,t2 = 1;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(s[i][j]=='*')
                {
                    while(j<c&&s[i][j]=='*')
                    {
                        mapx[i][j]=t1;j++;
                    }
                    t1++;
                }
            }
        }
        for(j=0;j<c;j++)
        {
            for(i=0;i<r;i++)
            {
                if(s[i][j]=='*')
                {
                    while(i<r&&s[i][j]=='*')
                    {
                        mapy[i][j]=t2;i++;
                    }
                    t2++;
                }
            }
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(s[i][j]=='*')
                {
                    g[mapx[i][j]].push_back(mapy[i][j]);
                    cout<<i<<" "<<j<<" "<<mapx[i][j]<<" "<<mapy[i][j]<<endl;
                }
            }
        }
        n = t1-1;
        cout<<hungry()<<endl;
    }
}


#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
char s[55][55];
const int maxn = 2555;
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
int n,t1,t2;
int hungary()
{
    tot=0;
    int i;
    memset(from,255,sizeof(from));
    for(i=1;i<t1;i++)
    {
        memset(use,0,sizeof(use));
        if(match(i))tot++;
    }
    return tot;
}
int mx[55][55],my[55][55];
int main()
{
    int i,j,n,m,T,k;
    scanf("%d",&T);
    int cas=0;
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%s",s[i]);
        for(i=0;i<n*m;i++)
            g[i].clear();
        memset(mx,0,sizeof(mx));
        memset(my,0,sizeof(my));
        t1 = 1;t2 = 1;
        int start=0,mark=0;
        for(i=0;i<n;i++)
        {
            int flag=-1;mark=0;
            for(j=0;j<m;j++)
            {
                if(s[i][j]=='#')
                {
                    if(flag!=-1)
                    {
                        if(mark)
                        {
                            for(k=start;k<j;k++)
                               mx[i][k]=t1;
                            t1++;
                        }
                    }
                    flag=-1;
                    mark=0;
                }
                else
                {
                    if(flag==-1)start=j;
                    if(s[i][j]=='o')mark=1;
                    if(s[i][j]=='*'||s[i][j]=='o')flag=j;
                }

            }
            if(flag!=-1)
            {
                if(mark)
                {
                    for(k=start;k<j;k++)
                       mx[i][k]=t1;
                    t1++;
                }
            }
        }

        start=0,mark=0;
        for(j=0;j<m;j++)
        {
            int flag=-1;mark=0;
            for(i=0;i<n;i++)
            {
                if(s[i][j]=='#')
                {
                    if(flag!=-1)
                    {
                        if(mark)
                        {
                            for(k=start;k<i;k++)
                            {
                                my[k][j]=t2;
                                if(s[k][j]=='o')
                                    g[mx[k][j]].push_back(t2);
                            }
                            t2++;
                        }
                    }
                    flag=-1;
                    mark=0;
                }
                else
                {
                    if(flag==-1)start=i;
                    if(s[i][j]=='o')mark=1;
                    if(s[i][j]=='*'||s[i][j]=='o')flag=i;
                }

            }
            if(flag!=-1)
            {
                if(mark)
                {
                    for(k=start;k<i;k++)
                    {
                        my[k][j]=t2;
                        if(s[k][j]=='o')
                                g[mx[k][j]].push_back(t2);
                    }
                    t2++;
                }
            }
        }
//        for(i=1;i<t1;i++)
//        {
//            for(j=0;j<g[i].size();j++)
//                cout<<g[i][j]<<" ";
//            cout<<endl;
//        }
        printf("Case :%d\n",++cas);
        printf("%d\n",hungary());
    }
}
